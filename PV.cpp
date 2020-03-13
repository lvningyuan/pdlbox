#include <iostream>
#include <pthread.h>
#include <queue>
#include <math.h>
#include <unistd.h>

#define SIZE 30


using namespace std;


template <class T>
class BlockQueue
{
  public:
    BlockQueue()
    :capacity(SIZE)
    {
      pthread_mutex_init(&lock, nullptr); 
      pthread_cond_init(&full, nullptr);
      pthread_cond_init(&empty, nullptr);
    }

    ~BlockQueue()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&full);
      pthread_cond_destroy(&empty);
    }

  void  LockQueue()
  {
    pthread_mutex_lock(&lock);
  }

  void UnlockQueue()
  {
    pthread_mutex_unlock(&lock);
  }

  void NotifyProduct()
  {
    pthread_cond_signal(&full);//库存不满了，可以生产了
  }

  void NotifyConsume()
  {
    pthread_cond_signal(&empty);//库存不为空了，可以来消费了
  }

  void ProductWait()
  {
    pthread_cond_wait(&full,&lock);//库存满了，等等生产   //注意这里要注重原子性
  }

  void ConsumeWait()
  {
    pthread_cond_wait(&empty, &lock);//库存空了，等等来
  }

  bool IsEmpty()
  {
    return q.empty();
  }

  bool IsFull()
  {
    return q.size() == capacity;
  }

  void PushData(T& data)
  {
    LockQueue();
    while(IsFull())
    {
      NotifyConsume();//先通知消费
      ProductWait();
    }
    NotifyConsume();//凡生产就通知消费可以来了
    q.push(data);
    UnlockQueue();
  }

  void PopData(T& data)
  {
    LockQueue();
    while(IsEmpty() )
    {
      NotifyProduct();//注意先通知生产
      ConsumeWait();
    }
    data = q.front();
    q.pop();
    UnlockQueue();
  }


  private:
    pthread_mutex_t lock;
    pthread_cond_t full;
    pthread_cond_t empty;
    int capacity;
    queue<T> q;
};



void* Consume(void* arg)
{
  BlockQueue<int>* q = (BlockQueue<int>*) arg;
  int data;
  while(true)
  {
    q->PopData(data);
    cout<<"消费产品: "<<data<<"谢谢惠顾"<<endl;
    usleep(1234);
  }
  return nullptr;
}



void* Product(void* arg)
{
  BlockQueue<int>* q = (BlockQueue<int>*) arg;
  srand((unsigned long) time(nullptr));
  while(true)
  {
    int data = rand() % 100;
    q->PushData(data);
    cout<<"生产产品:"<<data<<endl;
    usleep(1000);
  }

  return nullptr;
}



int main()
{
  BlockQueue<int> q;

  pthread_t t1, t2, t3, t4, t5;
  pthread_create(&t1,nullptr, Product,(void*)(&q));
 pthread_create(&t2,nullptr, Product,(void*)(&q));
  pthread_create(&t3,nullptr, Product,(void*)(&q));
  pthread_create(&t4,nullptr, Consume,(void*)(&q));
  pthread_create(&t5,nullptr, Consume,(void*)(&q));




  pthread_join(t1,nullptr);
  pthread_join(t2,nullptr);
  pthread_join(t3,nullptr);
  pthread_join(t4,nullptr);
  pthread_join(t5,nullptr);
  return 0;
}


