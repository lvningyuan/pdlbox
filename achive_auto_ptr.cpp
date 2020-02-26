#include <iostream>

using namespace std;

class Date
{
  public:
    Date(int year =1900, int month =1, int day =1 )
      :year_(year)
      ,month_(month)
      ,day_(day)
      { }
      

    int year_;
    int month_ ;
    int day_;
};

template <class T>
class Auto_ptr
{
  public:
    Auto_ptr( T* ptr = NULL)
    :ptr_(ptr)
    {}



    //auto_ptr :: 1 拷贝之后就会发生悬空，即被拷贝的对象内容消失，转移到了靠背后的对象中
    Auto_ptr( Auto_ptr<T>& prev)
      :ptr_(prev.ptr_)
    {
      prev.ptr_ = NULL;
    }
    ~Auto_ptr()
    {
      if( ptr_ )
        delete ptr_;
    }

    //auto_ptr  2  被赋值之后发生悬空,前面的对象悬空 ，即 this = tmp ;   tmp 悬空   a  = 2;   原有2中资源悬空
    


    Auto_ptr<T>& operator =(Auto_ptr<T>& tmp) 
    {
      // 检查是否自己给自己赋值
      if(this == &tmp)
      {
        return *this;
      }
      else 
      {
          if(! ptr_)
          {
            delete ptr_;//防止内存泄漏
          }
          
          //转移tmp 的资源到 this 中去
          ptr_ = tmp.ptr_;
          tmp.ptr_ = NULL;   //悬空  赋值者的资源
          return *this;//return *ptr_;
      }
  
    }

    T& operator *()
    {
      return * ptr_;
    }

    T* operator ->()
    {
      return ptr_;
    }


  private:
    T* ptr_;
};


int main()
{
   Auto_ptr<Date> a(new Date);
   Auto_ptr<Date> copy(a);


   //预期 下面两种方式都会发生错误
  // cout<<a->year_<<endl;
    a->year_  = 2018;
   return 0;
}

