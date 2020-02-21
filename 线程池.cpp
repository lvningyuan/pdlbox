#define __M_POOL_H__ 
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <stdlib.h>
#define MAX_THREAD 3
#define MAX_QUEUE 10

using namespace std;

class MyTask
{
  private:
    int data;
  public:
    MyTask(){}
    ~MyTask(){}

  void SetData(int _data)
  {
    data = _data;
  }

  void Run()
  {
    int t = rand() % 5;
    cout<<"thread :%lu sleep %d sec ,execute =data :%d\n"<<pthread_self()<<t<<data<<endl;
  }
};


class MyThreadPool
{

  private:
    int max_thread;
    int cur_thread;//当前线程池中的数量
    int keep_running;//停止线程池中线程的标志    即线程池是运行状态还是未运行状态
    int max_queue;//队列的最大节点数
   
    pthread_t* tid; //存储创建的线程id指针的数组
    std::queue<MyTask*> task_list;//任务队列
    pthread_mutex_t mutex; //互斥锁

    pthread_cond_t empty;//条件变量
    pthread_cond_t full;

    void ThreadLock()
    {
        pthread_mutex_lock(&mutex);
    }

    void ThreadUnlock()
    {
      pthread_mutex_unlock(&mutex);
    }

    void NotifyProduct()
    {
      pthread_cond_broadcast(&empty);
    }

    void NotifyConsume()
    {
      pthread_cond_signal(&full);
    }

    void ProductWait()
    {
      pthread_cond_wait(&full,&mutex);
    }

    void ConsumeWait()
    {
      pthread_cond_wait(&empty,&mutex);
    }

    bool QueueIsFull()
    {
      return task_list .size() == max_queue;
    }

    bool QueueIsEmpty()
    {
      return task_list .size() == 0;
    }
    
    void PushTask(MyTask* task)
    {
        task_list.push(task);
    }
    void PopTask(MyTask** task)
    {
      *task = task_list.front();
      task_list.pop();
    }

    void ThreadExit()
    {
      if(cur_thread != 1)//线程最少留一个线程
      { 
        --cur_thread;
        cout<<"thread %lu exit"<<pthread_self()<<endl;
        NotifyProduct();
        pthread_exit(NULL);//回收退出线程的资源
      }
    }
    bool ThreadIsRunning()
    {
      return keep_running != 0;
    }

    static void* thread_routine(void* arg)   //执行流  具体的执行
    {
      MyThreadPool* pthreadpool = (MyThreadPool*) arg;
      while(true)
      {
        pthreadpool->ThreadLock();
          //1  线程池启用  ，任务队列为空,即 没有要执行的任务 ，则该线程挂起等待
        while(pthreadpool->ThreadIsRunning() && pthreadpool -> QueueIsEmpty())
        pthreadpool->ConsumeWait();


          //2  线程池未启用，且任务队列为空 ，则退出本线程
          if(!pthreadpool->ThreadIsRunning()  &&  pthreadpool->QueueIsEmpty())
          {
              pthreadpool->ThreadUnlock();
              pthreadpool->ThreadExit();
          }


        //3  线程池启用了，但任务队列不为空  ，则等待任务队列执行完毕 ，再退出
        //怎么执行让任务执行完？  我们可以获取一个任务，并模拟执行
       

         // 能走到这里，说明下边这种情况成立
        //while(pthreadpool->ThreadIsRunning() && pthreadpool->QueueIsEmpty())
        {
            MyTask* task;//输出型参数
            //获取任务
            pthreadpool->PopTask(&task);//这里注意，我们需要修改的是指针，所以可以用一级指针的引用，或者二级指针接收

            pthreadpool->NotifyProduct();
            pthreadpool->ThreadUnlock();
            
            //执行任务
            task->Run();
        }
          return NULL;
      }
    }


      

  public:
    MyThreadPool( int _max_thread =MAX_THREAD, int _max_queue =MAX_QUEUE )
      :max_thread(_max_thread)
      ,cur_thread(_max_thread)
      ,keep_running(1)//默认线程池是启用着的
      ,max_queue(_max_queue)
  {
      cout<<"create threads" <<max_thread<<" task--queue  "<<max_queue<<endl;
      
      tid =(pthread_t*)malloc(sizeof(pthread_t) * _max_thread);//申请_max_thread个线程的pid数组，保存线程的id,
      pthread_mutex_init(&mutex,NULL);
      pthread_cond_init(&full,NULL);
      pthread_cond_init(&empty,NULL);

      //创建固定数量的线程 ，等待执行任务
      for(int i =0; i<_max_thread; ++i)
      {
        int ret = pthread_create(&tid[i],NULL,thread_routine,(void*)this);
        if(ret != 0)
        {
            cout<<"thread create error"<<endl;
            exit(0);
        }

      //否则，创建成功 ，分离该创建成功的线程
      pthread_detach(pthread_self());
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
    cout<<"push  Task"<<endl;
    //++cur_thread;
    NotifyConsume();
    ThreadUnlock(); 
    return true;
  }

void StopThreadPool()
{
  //首先判断线程池是否已经退出
  if(keep_running == 0)
    return;
  
  ThreadLock();
  keep_running =0;//设置线程池状态为退出状态

  
  while(cur_thread > 0)
  {
    ProductWait();//   给生产加锁  不再生产
  }
  //等所有线程 将 任务都完成 再退出
  ThreadUnlock();
}
};


int main()
{
  MyTask task[10]; //10个任务
  MyThreadPool pool;

  for(int i=0; i<10; ++i)
  {
    task[i].SetData(i);
    pool.AddTaskToPool(&task[i]);
  }

  pool.StopThreadPool();
  return 0;
}
