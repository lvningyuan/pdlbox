#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void* handler(void* arg)
{
  (void)arg;
  while(1)
  {
    printf("i'm thread 1\n");
    sleep(1);
  }
    return NULL;
}

int main()
{
pthread_t t1;
 int ret = pthread_create(&t1,NULL,handler,NULL);//pthreads 函数成功返回0  失败将错误代码通过返回值返回
if(ret != 0)
{
  fprintf(stderr,"pthread_create : %s\n",strerror(ret));
  exit(1);
}

// ret = pthread_create(&t2,NULL,handler,NULL);//pthreads 函数成功返回0  失败将错误代码通过返回值返回
while(1)
{
  printf("i'm  main pthread\n");
  sleep(1);
}
  return 0;
}
