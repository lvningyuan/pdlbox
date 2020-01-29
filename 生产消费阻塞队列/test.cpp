#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <queue>
#include <unistd.h>

#define NUM 50


class BlockQueue
{

  public:

    bool isFull()
    {
      return  q.size() == cap;
    }

    bool isEmpty()
    {
      return q.size() == 0;
    }

    void lockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void unLockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    void productWait()
    {
      pthread_cond_wait(&full,&lock);
    }

    void consumeWait()
    {
      pthread_cond_wait(&empty,&lock);
    }

    void NotifyConsume()
    {
      pthread_cond_signal(&full);
    }

    void NotifyProduct()
    {
      pthread_cond_broadcast(&empty);
    }

    BlockQueue(int cap_ = NUM)
      :cap(cap_)
    {
      pthread_mutex_init(&lock,NULL);
      pthread_cond_init(&full,NULL);
      pthread_cond_init(&empty,NULL);
    }
    void pushData(const int& data)
    {
      lockQueue();//加锁

      while(isFull())//q  仓库满 陷入等待
      {
        NotifyConsume();//满的话就通知消费者前来消费
        std::cout<<"queue isfull ,Notifyed consume data ,product stop,"<<std::endl;
        productWait();//生产陷入等待，等待消费 ，消费之后 isfull不成立，这时push_   
      }
      q.push(data);//q  仓库有货，通知消费者可以前来消费
      NotifyConsume();

      unLockQueue();//操作完成，解锁
    }

    void popData(int& data)//输出型参数
    {
      lockQueue();//首先加互斥锁

      while(isEmpty())
      {
        NotifyProduct();//一旦没货，通知生产者生产
        std::cout<<"q is empty,notify product,consume stop,"<<std::endl;
        consumeWait();//消费陷入等待
      }

      data = q.front();
      q.pop();
      NotifyProduct();

      unLockQueue();
    }


    ~BlockQueue()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&full);
      pthread_cond_destroy(&empty);
    }


  private:

    std::queue <int> q;//仓库//阻塞队列
    int cap ;//容量
    pthread_mutex_t lock;//互斥锁
    pthread_cond_t  full;//库满
    pthread_cond_t  empty;//库空 

};


void* consume(void* arg)
{
  BlockQueue* bqp = (BlockQueue*)arg;
  int data;
  while(1)
  {
    bqp->popData(data);
    std:: cout<<"Consume  data:"<< data<<std::endl;
    sleep(2);
  }
  return NULL;
}


void* product(void* arg)
{
  BlockQueue* bqp =(BlockQueue*)arg;

  srand((unsigned long)time(NULL));
  while(1)
  {
    int data =rand() % 50;
    bqp -> pushData(data);
    std::cout<<"product data "<<data<<std::endl;
    sleep(2);
  }
  return NULL;
}

int main()
{
  BlockQueue bq;//阻塞队列对象
  pthread_t t1,t2,t3,t4,t5,t6,t7;

  pthread_create(&t1,NULL,product,(void*)&bq);
  pthread_create(&t2,NULL,product,(void*)&bq);
  pthread_create(&t3,NULL,product,(void*)&bq);
  pthread_create(&t4,NULL,product,(void*)&bq);
  pthread_create(&t5,NULL,consume,(void*)&bq);
  pthread_create(&t6,NULL,consume,(void*)&bq);
  pthread_create(&t7,NULL,consume,(void*)&bq);


  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  pthread_join(t4,NULL);
  pthread_join(t5,NULL);
  pthread_join(t6,NULL);
  pthread_join(t7,NULL);

  return 0;
}
