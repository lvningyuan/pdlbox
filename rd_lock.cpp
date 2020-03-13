#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>

#define RD  10
#define WR  4

using namespace std;


pthread_rwlock_t lock;
volatile size_t ticket =100;

struct ThreadAttr
{
  std::string id;
  pthread_t tid;
};

string ApendReaderInfo(size_t i)//i 是创建的reader的序号
{
  ostringstream oss("Thread reader ", ios_base::ate);//ios_base_ate  追加方式
  oss << i+1;
  return oss.str();
}

string ApendWriterInfo(size_t i)//i 是创建的reader的序号
{
  ostringstream oss("Thread writer ", ios_base::ate);//ios_base_ate  追加方式
  oss << i+1;
  return oss.str();
}

void* readers_do(void* arg)
{
  pthread_rwlock_rdlock(&lock);
  string* id = (string*)arg;
  while(true)
  {
    cout<<*id<<"余量: "<<ticket<<endl;
    pthread_rwlock_unlock(&lock);
    usleep(4);
    break;
  }
 
  return nullptr;
}

void* writers_do(void* arg)
{
  pthread_rwlock_wrlock(&lock);
  string* id = (string*) arg;
  while(true)
  {
    if(ticket <= 0)
    {
      pthread_rwlock_unlock(&lock);
      break;
    }
    cout<<*id<<"当前票量: "<< --ticket<<endl;
    pthread_rwlock_unlock(&lock);
    usleep(2);
  }
  return nullptr;
}


void readers_init(vector<ThreadAttr>& vec)
{
  for(size_t i =0; i < vec.size(); ++i)
  {
    vec[i].id = ApendReaderInfo(i);
    pthread_create(&vec[i].tid,nullptr,readers_do, (void*)&vec[i].id );
  }
}

void writers_init(vector<ThreadAttr>& vec)
{
  for(size_t i=0; i < vec.size(); ++i)
  {
    vec[i].id =ApendWriterInfo(i);
    pthread_create(&(vec[i].tid),nullptr, writers_do, (void*)&vec[i].id);
  }
}

void join_threads(vector<ThreadAttr>& vec)
{

  //按创建的逆序回收线程资源，因为pthread_join 是阻塞式等待的 ，正序回收的话可能导致陷入死锁
  for(auto it = vec.rbegin(); it != vec.rend(); ++it)
  {
    pthread_join(it->tid, nullptr);
  }
}



int main()
{
 // init_rwlock_init(&lock,nullptr);
  vector<ThreadAttr> readers(RD);
  vector<ThreadAttr> writers(WR);
  
  readers_init(readers);
  writers_init(writers);

  join_threads(writers);
  join_threads(readers);

  pthread_rwlock_destroy(&lock);
  return 0;
}
