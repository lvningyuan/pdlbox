#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

void*  handler1(void* arg)
{
  (void)arg;
  printf("thread 1 running...\n");
  sleep(1);
  int *p = (int*) malloc(sizeof(int));
  *p =1;
  return (void*)p;//线程结束方式1  return 
}


void*  handler2(void* arg)
{
  (void)arg;
  printf("thread 2 running...\n");
  sleep(2);
  int *p = (int*) malloc(sizeof(int));
  *p =2;
   pthread_exit((void*)p);//线程结束方式2  pthread_exit;exit用来保存退出状态 必须是全局变量或者malloc/new 申请的
}


void*  handler3(void* arg)
{
  (void)arg;
  while(1)
  {
  printf("thread 3 running...\n");
  sleep(1);
  }
  return NULL;
}


int main()
{
  pthread_t tid;
  void*ret;//接收退出码

//thread 1
 pthread_create(&tid,NULL,handler1,NULL);
 pthread_join(tid,&ret);//线程等待  join的第二个参数 指向进程的推出状态，退出状态是一个一级指针
 printf("thread return ,thread id :%x,return code:%d\n",tid,*(int*)ret);
 free(ret);

//thread 2
 pthread_create(&tid,NULL,handler2,NULL);
 pthread_join(tid,&ret);//线程等待  join的第二个参数 指向进程的推出状态，退出状态是一个一级指针
 printf("thread return ,thread id :%x,return code:%d\n",tid,*(int*)ret);
 free(ret);//清空指针内容
 
 
//thread 3
 pthread_create(&tid,NULL,handler3,NULL);
 sleep(6);
 pthread_cancel(tid);//取消关联线程
 pthread_join(tid,&ret);//线程等待  join的第二个参数 指向进程的推出状态，退出状态是一个一级指针
 if(ret == PTHREAD_CANCELED)
      printf("thread return ,thread id :%x,return code:PTHREAD_CANCELED  \n",tid );
 else
      printf("thread return ,thread id :%x,return code：NULL\n",tid);

//ret 为栈上的指针，不用free ;
 return 0;
 //存在内存泄漏 p
}

