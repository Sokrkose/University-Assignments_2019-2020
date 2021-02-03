#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>


typedef void (*sighandler_t)(int); /* type definition for return handler */
static jmp_buf jbuf;            /* setup as global/static for sigsetjmp and siglongjmp */

/* signal handler */
void handler(int signo)
{
    siglongjmp(jbuf, 0);
}


int safeWrite(int* ptr, int val)
{
  int status = 0;

  signal(SIGSEGV, handler);

  int saved_env = sigsetjmp(jbuf, 10000);

  if(saved_env == 0){
    *ptr = val;
    status = 0;
  }else{
    status = 1;
  }

  return status;

}