#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sstream>
#include <vector>


volatile int ticket =100;//线程函数操作，handler 为 内核调用的函数，编译器不做处理 ，因此告诉编译器 ，每次从内存读取 ticket 
pthread_rwlock_t rwlock;

//handler  读
//读锁 获取当前票量
void* reader(void* arg)
{
char* id =(char*) arg;
while(1)
{
  pthread_rwlock_rdlock(&rwlock);
  if(ticket <= 0)
  {
    pthread_rwlock_unlock(&rwlock);
    break;
  }
  printf("%s: %d\n",id,ticket);
  pthread_rwlock_unlock(&rwlock);
  usleep(5000);
}
return NULL;
}

//  handler 写锁   出票
void* writer(void* arg)
{
char* id = (char*) arg;
while(1)
{
  pthread_rwlock_wrlock(&rwlock);
  if(ticket <= 0)
  {
  pthread_rwlock_unlock(&rwlock);
  break;
  }
 printf("%s: %d\n",id,--ticket);
 pthread_rwlock_unlock(&rwlock);
 usleep(2000);
}
return nullptr;
}


struct ThreadAttr
{
  pthread_t tid;//线程id
  std::string id ;//线程的编号
};


//   获取读者线程编号
std::string create_reader_id(std::size_t i)
{
  //利用stringstream  进行 string 拼接
  std::ostringstream oss("thread reader ",std::ios_base::ate);
  oss<<i;
  return oss.str();
}


//  获取  写着 线程的编号（人为）  并不是 线程id  
std::string create_writer_id(std::size_t i)
{
  //利用 stringstream 进行 string 拼接   ， “thread writer”为 C类型的 字符串，所以 这样拼接一下
  std::ostringstream oss("thread writer ",std::ios_base::ate);//std::ios_base::ate //打开文件，并立即定位到文件末尾
  oss<<i;//将 i  拼接到 oss 末尾   oss  为临时对象
  return oss.str();//oss对象   以字符串的方式返回
}


//创建读者线程
void init_readers(std::vector<ThreadAttr>& vec)
{
  for(std::size_t i =0; i<vec.size(); ++i)
  {
    vec[i].id = create_reader_id(i);
    pthread_create(&vec[i].tid ,   nullptr,   reader,    (void*)vec[i].id.c_str()); //创建读者线程
  }
}
//  创建写者线程
void init_writers(std:: vector<ThreadAttr>& vec)
{
for(std::size_t i=0; i<vec.size(); ++i)
{
  vec[i].id =create_writer_id(i);

  pthread_create(&vec[i].tid, nullptr, writer, (void*)vec[i].id.c_str());
}
}

//等待回收线程的资源  
void join_threads(std::vector<ThreadAttr> &vec )
{
//逆序回收线程资源
  for(std::vector<ThreadAttr> ::const_reverse_iterator it = vec.rbegin();   it != vec.rend(); ++it)//迭代器类型 ，逆序回收,ThreadAttr迭代器
  {
    pthread_t const& tid  = it->tid;
    pthread_join(tid,nullptr);
  }
}



//  初始化 读写锁
void init_rwlock()
{
#if 0   //条件编译
  //写锁优先
  pthread_rwlockattr_t attr; //读写锁变量
  pthread_rwlock_rdlockattr_init(&attr);  //初始化 attr
  pthread_rwlockattr_setkind_np(&attr,PTHREAD_RWLOCK_PERFER_WRITER_NONRECURSIVE_NP); //写优先，不共享
  pthread_rwlockattr_destroy(&attr);//释放  读写锁变量
#else 
  pthread_rwlock_init(&rwlock,nullptr);
#endif 
}

int main()
{
const std::size_t read_nr = 1000;
const std::size_t writer_nr =20;
//两个  vector 数组
std::vector<ThreadAttr> readers(read_nr);
std::vector<ThreadAttr> writers(writer_nr);

init_rwlock();

init_readers(readers);
init_writers(writers);

join_threads(readers);
join_threads(writers);

pthread_rwlock_destroy(&rwlock);
return 0;
}
