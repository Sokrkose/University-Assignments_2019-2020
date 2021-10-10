#include "covidTrace_v5.h"
#include <signal.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int timeOfExperiment = 259200; //259200 = (30*24*60*60)/10, this is the number of times that the while loop is going to run
int SelfTestTime = 1440;       //(4*60*60/10), this is the period that we make covid self-test. 4 minutes.
double timestep = 0.1;         // 0.1 = 10sec/100
int counter = 0;
int firstTimeFlag = 0;

struct itimerval timer;
struct sigaction sa;

void signalHandler(){
    
    gettimeofday(&timestamp, NULL);
    fprintf(timesFile, "%ld;%ld\n", timestamp.tv_sec, timestamp.tv_usec);
    
    struct timeval start, end, dt;
    
    if(firstTimeFlag == 0){
        firstTimeFlag = 1;
        gettimeofday(&reference, NULL);   
    }

    possibleContact(BTNearMe());
    updateContacts();
    
    //covid test every 4 hours (4*60*60/10)
    if(counter % SelfTestTime == 0){
        if(testCOVID() == 1){
            uploadContacts();
        }
    }

}

void timerInit(void ){

    double flooredTime = floor(timestep);

    struct timeval d;
    d.tv_sec = (int ) flooredTime;
    d.tv_usec = (int ) (1e6*(timestep - flooredTime));
    
    timer.it_value = d;
    timer.it_interval = d;

    memset(&sa, 0, sizeof(sa ));
    sa.sa_handler = &signalHandler;
    sigaction(SIGALRM, &sa, NULL); 

}

void timerStop(void ){
    
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

}

void main(int argc, char **argv){

    timesFile = fopen("./times.csv", "w+");
    uploadedContactsFile = fopen("./uploadedContacts.txt", "w+");

    MACs = (macaddress* ) malloc(N * sizeof(macaddress ));
    createListOfMACs(MACs, N);

    timerInit();

    //here we start the simulation
    setitimer(ITIMER_REAL, &timer, NULL);

    struct timeval start, end, dt;
    gettimeofday(&start, NULL);
    while(counter++ < timeOfExperiment){

        printf("Counter = %d\n", counter);
        sleep(99999999);
    
    }
    gettimeofday(&end, NULL);
    timersub(&end, &start, &dt);
    printf("\nElapse time: %ld seconds & %ld microseconds\n", dt.tv_sec, dt.tv_usec);

    timerStop();

    fclose(timesFile);
    free(MACs);
    
}