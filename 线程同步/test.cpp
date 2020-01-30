#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

pthread_cond_t cond; //define  
pthread_mutex_t mutex;

void* r1(void* arg)
{
  (void) arg;
  while(1)
  {
    pthread_cond_wait(&cond,&mutex);//等待条件满足   再执行
    printf("活动\n");
  }
  return NULL;
}

void* r2(void* arg)
{
  (void) arg;
  while(1)
  {
    pthread_cond_signal(&cond);//唤醒等待
    sleep(1);
  }
  return NULL;
}


int main()
{
  pthread_t t1, t2;

  pthread_cond_init(&cond,NULL);//初始化 cond 条件变量
  pthread_mutex_init(&mutex,NULL);//初始化 lock

  pthread_create(&t1,NULL,r1,NULL);
  pthread_create(&t2,NULL,r2,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  pthread_mutex_destroy(&mutex);//释放锁
  pthread_cond_destroy(&cond);//释放条件变量

  return 0;
}
