#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define QUEUESIZE 10
#define LOOP 50000

void* producer(void* args);
void* consumer(void* args);

struct workFunction{
  void* (*work)(void* );
  void* arg;
};

typedef void* (*work)(void* );

void* task(void* i){
  printf("I am the thread with ID = %u\n", i);
}

work job = task;

typedef struct{
  struct workFunction buf[QUEUESIZE];
  long head, tail;
  int full, empty;
  pthread_mutex_t* mut;
  pthread_cond_t *notFull, *notEmpty;
}queue;

queue* queueInit(void );
void queueDelete(queue* q);
void queueAdd(queue* q, struct workFunction in);
void queueDel(queue* q, struct workFunction* out);

struct timeval start[QUEUESIZE], finish[QUEUESIZE], start_time, finish_time, program_start, program_finish, after_if_time;
long long s[QUEUESIZE], f[QUEUESIZE], interval[QUEUESIZE], p_s, p_f, after_if, dt = 0;
long volatile measurements;
double volatile average = 0.0;

FILE *file;

int main(int argc, char* argv[])
{

  if(argc != 3) {
    printf("Wrong Command !!!\n");
    return -1;
  }

  gettimeofday(&program_start, NULL);
  p_s = (long long )((long long ) program_start.tv_sec * 1000000 + (long long ) program_start.tv_usec);
  
  char* str = "output_file";
  file = fopen(str, "a");
  
  queue* fifo;

  int prod_number = atoi(argv[1]);
  int cons_number = atoi(argv[2]);
  pthread_t pro[prod_number], con[cons_number];

  printf("Number of Porducer Threads is %d\n", prod_number);
  printf("Number of Consumer Threads is %d\n", cons_number);

  fifo = queueInit();
  if (fifo ==  NULL){
    fprintf(stderr, "main: Queue Init failed.\n");
    exit(1);
  }

  for (int i = 0; i < cons_number; i++)
    pthread_create(con + i, NULL, consumer, fifo);

  for (int i = 0; i < prod_number; i++)
    pthread_create(pro + i, NULL, producer, fifo);
  
  for (int i = 0; i < cons_number; i++)
    pthread_join(con[i], NULL);

  for (int i = 0; i < prod_number; i++)
    pthread_join(pro[i], NULL);
  
  queueDelete(fifo);

  fclose(file);

  return 0;
}

void* producer(void* q)
{
  queue* fifo;
  fifo = (queue* ) q;

  struct workFunction product;

  long counter;
  for(int i = 0; i < LOOP; i++){
    pthread_mutex_lock(fifo->mut);

    while(fifo->full){
      printf("producer: queue FULL\n");
      pthread_cond_wait(fifo->notFull, fifo->mut);
    }

    product.work = job;
    product.arg = pthread_self();
    
    queueAdd(fifo, product);
    gettimeofday(&start_time, NULL);

    if(fifo->tail - 1 == -1){
      counter = QUEUESIZE - 1;
    }else{
      counter = fifo->tail - 1;
    }
    //printf("producer: produced %ld\n", counter);

    s[counter] = (long long )((long long ) start_time.tv_sec * 1000000 + (long long ) start_time.tv_usec);
    //printf("s = %lld\n", s[counter]);

    pthread_mutex_unlock(fifo->mut);
    pthread_cond_signal(fifo->notEmpty);
  }

  return(NULL);
}

void* consumer(void* q)
{
  queue* fifo;
  fifo = (queue* ) q;

  struct workFunction product;

  long counter = 0;
  while(1){
    pthread_mutex_lock(fifo->mut);
    
    while(fifo->empty){
      printf("consumer: queue EMPTY\n");
      pthread_cond_wait(fifo->notEmpty, fifo->mut);
    }

    product = fifo->buf[fifo->head];

    queueDel(fifo, &product);
    gettimeofday(&finish_time, NULL);

    if(fifo->head - 1 == -1){
      counter = QUEUESIZE - 1;
    }else{
      counter = fifo->head - 1;
    }
    //printf("consumer: recieved %ld\n", counter);

    f[counter]= (long long)((long long) finish_time.tv_sec * 1000000 + (long long ) finish_time.tv_usec);
    //printf("f = %lld\n", f[counter]);
    interval[counter] = f[counter] - s[counter];
    //printf("interval = %lld\n", interval[counter]);
    average = (double)(average * measurements + interval[counter] - dt)/(double)(++measurements);
    printf("average = %f\n", average);

    pthread_mutex_unlock(fifo->mut);
    pthread_cond_signal(fifo->notFull);

    product.work(product.arg);

    gettimeofday(&program_finish, NULL);
    p_f = (long long )((long long ) program_finish.tv_sec * 1000000 + (long long ) program_finish.tv_usec);

    if( p_f - p_s > 20000000 ){
        fprintf(file, "%f\n", average);
        fclose(file);
        exit(0);
    }

    gettimeofday(&after_if_time, NULL);
    after_if = (long long )((long long ) after_if_time.tv_sec * 1000000 + (long long ) after_if_time.tv_usec);
    dt = after_if - p_f;

  }

  return(NULL);
}

queue* queueInit(void )
{
  queue *q;

  q = (queue *)malloc(sizeof(queue));
  if(q == NULL) return(NULL);

  q->empty = 1;
  q->full = 0;
  q->head = 0;
  q->tail = 0;

  q->mut = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(q->mut, NULL);

  q->notFull = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
  pthread_cond_init(q->notFull, NULL);

  q->notEmpty = (pthread_cond_t *) malloc(sizeof(pthread_cond_t));
  pthread_cond_init(q->notEmpty, NULL);

  return(q);
}

void queueDelete (queue* q)
{
  pthread_mutex_destroy(q->mut);
  free(q->mut);

  pthread_cond_destroy(q->notFull);
  free(q->notFull);

  pthread_cond_destroy(q->notEmpty);
  free(q->notEmpty);

  free(q);
}

void queueAdd(queue* q, struct workFunction in)
{
  q->buf[q->tail] = in;
  q->tail++;

  if(q->tail == QUEUESIZE)
    q->tail = 0;

  if(q->tail == q->head)
    q->full = 1;

  q->empty = 0;

  return;
}

void queueDel(queue* q, struct workFunction* out)
{
  *out = q->buf[q->head];

  q->head++;
  if(q->head == QUEUESIZE)
    q->head = 0;

  if(q->head == q->tail)
    q->empty = 1;

  q->full = 0;

  return;
}