#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


//共享指针 ，原理 采用 浅拷贝 + 引用计数的方法

template <class T>
class Shared_ptr
{
  public:
    Shared_ptr(T* ptr = nullptr)
    :ptr_(ptr)
    ,pMutex_(new mutex)
    ,pCount_(new int(1))
  {}
    
    ~Shared_ptr()
    {
      Relese();
    }

    Shared_ptr(const Shared_ptr<T>& p)
      :ptr_(p.ptr_)
       ,pMutex_(p.pMutex_)
       ,pCount_(p.pCount_)
    {
          AddpCount();//引用计数
    }
    
    Shared_ptr& operator = (Shared_ptr<T>& sp)
    {
        if(&sp  !=  this )//防止给自己赋值
        {
            delete this->ptr_ ;//先释放自己的资源防止内存泄漏

          //标注资源位置
            this->ptr_ = sp.ptr_;
            this->pCount_ = sp.pCount_;
            this->pMutex_ = sp.pMutex_;

            AddpCount();
        }
        return *this;
    }
    

    int Get()
    {
      return *pCount_;
    }
    
    T& operator *(){return *ptr_; }
    T* operator ->(){return ptr_; }



  private:
  void AddpCount()
 {
   pMutex_->lock();
   ++(*pCount_);//这里的引用计数参数必须是指针类型,  因为我们只保留一份数据，传值的话就保留了多份数据，不符合引用计数的思想
   pMutex_->unlock();
 }


  void Relese()
 {
   bool delete_falg = false;
   pMutex_->lock();
   --*pCount_;
   if(*pCount_ == 0)
     delete_falg = true;

   pMutex_->unlock();
  
  if(delete_falg == true)
  {
      delete pCount_;
      delete pMutex_;
      delete ptr_;
  }
 }

    T* ptr_;
    mutex* pMutex_;
    //这里的引用计数参数必须是指针类型,  因为我们只保留一份数据，传值的话就保留了多份对象，不符合引用计数的思想
    int* pCount_;
};
