#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <sched.h>//cpu 控制
int ticket = 100;
pthread_mutex_t mutex;//define

void* sell(void * arg)
{
  char** id = (char**) arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);//LOCK
    if(ticket > 0)
    {
      usleep(1000);//模拟购票过程 //这样会导致 并发执行的出错 ，即线程切换，出现的读脏数据,解决策略是 加锁
      printf("thread %s 购票成功，当前余量%d\n",*id,--ticket);
      pthread_mutex_unlock(&mutex);
      //sched_yield();//让优先级大于本线程的线程执行
    }
    else 
    {
      pthread_mutex_unlock(&mutex);
      break;
    }
  }
  return NULL;
}

int main ()
{
  pthread_t  t1,t2,t3,t4;
  pthread_mutex_init(&mutex,NULL);// init  lock 

  std::string a[4]={"thread 1","thread 2","thread 3","thread 4"};
  pthread_create(&t1,NULL,sell,&a[0]);
  pthread_create(&t2,NULL,sell,&a[1]);
  pthread_create(&t3,NULL,sell,&a[2]);
  pthread_create(&t4,NULL,sell,&a[3]);

  pthread_join (t1,NULL);
  pthread_join (t2,NULL);
  pthread_join (t3,NULL);
  pthread_join (t4,NULL);

  pthread_mutex_destroy(&mutex);// destroy lock 

  return 0;
}
