//#ifndef __M_POOL_H__
#define __M_POOL_H__ 
#include <iostream>
#include <queue>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREAD 3  //最大线程数
#define MAX_QUEUE 10  //队列长度

class MyTask
{
  private:
    int data;
  public:
    MyTask(){}
    ~MyTask(){}


    void SetData(int _data)
    {
      data =_data;
    }

    void Run()
    {
      int t = rand()% 5;
      printf("thread : %lu sleep %d sec ,execute data : %d\n",pthread_self(),t,data);
      sleep(1);
    }
};

class MyThreadPool
{
  private:
    int max_thread;//线程池中最大线程数
    int cur_thread;//当前线程数
    int keep_running;//用于停止线程池中线程的标志
    int max_queue;//队列中最大节点数
    pthread_t* tid;//线程id
    std::queue<MyTask*> task_list;//任务列表
    pthread_mutex_t mutex; //互斥量
    pthread_cond_t empty;//条件
    pthread_cond_t full;//条件
    void ThreadLock()
    {
       pthread_mutex_lock(&mutex);
    }

    void ThreadUnLock()
    {
      pthread_mutex_unlock(&mutex);
    }

    void ConsumeWait()
    {
      pthread_cond_wait(&empty,&mutex);
    }

    void ProductWait()
    {
      pthread_cond_wait(&full,&mutex);
    }

    void ConsumeNotify()
    {
      pthread_cond_signal(&empty);
    }

    void ProductNotify()
    {
        pthread_cond_broadcast(&full);
    }

    bool ThreadIsRunning()
    {
      return keep_running ==0;
    }

    void ThreadExit()
    {
      cur_thread--;//当前线程数-1
      printf("thread :%lu  exit\n",pthread_self());
      // 通知主线程线程池中有线程退出
      ProductNotify();
      //释放线程资源
      pthread_exit(NULL);

    }

    bool QueueIsEmpty()
    {
      return task_list .size() == 0;
    }

    bool QueueIsFull()
    {
      return task_list.size() == max_queue;
    }


    void PopTask(MyTask** task)
    {
      *task = task_list.front();
      task_list.pop();
    }

    void PushTask(MyTask* task)
    {
      task_list.push(task);
    }

    static void* thread_routine(void *arg)
    {
      MyThreadPool *pthreadpool = (MyThreadPool*) arg;
      while(1)
      {
        pthreadpool ->ThreadLock();
        //如果当前是运行状态， 并且没有任务则挂起等待 
        while(pthreadpool->QueueIsEmpty()  && pthreadpool->ThreadIsRunning()) 
          pthreadpool->ConsumeWait();

        //若果当前不是运行状态，并且没有任务，那么退出线程
        //非运行              队列中有任务则需要将任务执行完毕后才可退出
        if(! pthreadpool->ThreadIsRunning() && pthreadpool->QueueIsEmpty()  )
        {
          pthreadpool->ThreadUnLock();
          pthreadpool->ThreadExit();
        }

        //能执行到这里，说明Queue任务队列 不为空
        MyTask *task;
        pthreadpool->PopTask(&task);
        pthreadpool->ProductNotify();
        pthreadpool->ThreadUnLock();

        //不能在锁内执行任务，否则导致其他线程饥饿
        task->Run();

      }

      return NULL;
    }

  public:

    MyThreadPool(int _max_thread = MAX_THREAD,int _max_queue = MAX_QUEUE)
      :max_thread(_max_thread)
       ,cur_thread(_max_thread)
       ,max_queue(_max_queue)
       ,keep_running(1)
  {
    int i =0;
    printf("create thread %d-%d\n",max_thread,max_queue);

    tid = (pthread_t*)malloc(sizeof(pthread_t)* _max_thread);
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&empty,NULL);
    pthread_cond_init(&full,NULL);
    // 创建笃定数量的线程   等待执行任务
    //
    for(i=0;i<_max_thread;++i)
    {
      int ret = pthread_create(&tid[i],NULL,thread_routine,(void*)this);
      if(ret  != 0)
      {
        printf("create thread errorn\n");
        exit(0);
      }
      pthread_detach(tid[i]);
    }    
  }

    ~MyThreadPool()
    {
      pthread_mutex_destroy(&mutex);
      pthread_cond_destroy(&full);
      pthread_cond_destroy(&empty);
    }

    bool AddTaskToPool(MyTask* task)
    {
      ThreadLock();
      while(QueueIsFull())
      {
        ProductWait();
      }

      PushTask(task);
      printf("add task to pool\n");
      ConsumeNotify();
      ThreadUnLock();
      return true;
    }

    void StopThreadPool()
    {
      //如果已经调用过线程池退出，那么返回
      if(keep_running == 0)
        return ;


      ThreadLock();
      keep_running = 0;
      //如果还有线程 没退出，挂起等待,直到所有线程执行完毕后退出
      while(cur_thread > 0)
      {
        ProductWait();
      }

      ThreadUnLock();
    }
};



int main()
{
  MyTask task[10];

  int i; 
  MyThreadPool pool;
  for(i=0; i <10; ++i)
  {
    task[i].SetData(i);
    pool.AddTaskToPool(&task[i]);
  }

  pool.StopThreadPool();
  return 0;
}
