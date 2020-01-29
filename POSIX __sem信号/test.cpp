#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <vector>
#include <unistd.h>

#define NUM 16

class RingQueue
{
  private:
    std::vector<int>q;
    int cap;
    sem_t data_sem;
    sem_t space_sem;
    int consume_step;
    int product_step;


  public:

    RingQueue(int _cap = NUM)
      :q(_cap)//初始化 q的长度
       ,cap(_cap)
  {
    sem_init(&data_sem,0,0);//数据信号量，  0线程      0信号量初始值为 0
    sem_init(&space_sem,0,cap);//空间信号量  0： 线程 ，0：初值0
    consume_step=0;
    product_step=0;
  }
    void PutData(const int& data)
    {
      sem_wait(&space_sem);//申请资源     //等待信号量，等待被唤醒 ，执行后续
      q[consume_step] = data;
      consume_step++;
      consume_step %= cap;//循环操作
      sem_post(&data_sem); //v  释放资源  //发布信号量
    }

    void GetData(int& data)
    {
      sem_wait(&data_sem); // P   //等待信号量
      data = q[product_step];
      product_step++;
      product_step %= cap;
      sem_post(&space_sem);
    }

    ~RingQueue()
    {
      sem_destroy(&data_sem);
      sem_destroy(&space_sem);
    }
};

void* consume(void* arg)
{
  RingQueue *rqp = (RingQueue*)arg;
  int data ;
  while(1)
  {
    rqp->GetData(data);
    std::cout<<"consume data"<<data <<std::endl;
    sleep(1);
  }
  return NULL;
}

void* product(void* arg)
{
  RingQueue *rqp =(RingQueue*) arg;
  srand((unsigned long) time(NULL));
  int  data;
  while(1)
  {
    data = rand() % 1024;
    rqp->PutData(data);
    std::cout<<"product data done: "<<data<<std::endl;
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t t1 ,t2;
  RingQueue rq;

  pthread_create(&t1,NULL,product,(void*)&rq );
  pthread_create(&t2,NULL,consume,(void*)&rq );

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  return 0;
}
