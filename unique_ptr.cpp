#include <iostream>


using namespace std;

//unique_ptr 独一无二的只能指针，简单粗暴 ，防止拷贝，防止赋值

class Date
{
  public:
    Date(int year , int month, int day)
    :year_(year)
    ,month_(month)
    ,day_(day) 
  {}

  
    int year_;
    int month_;
    int day_;
};

template <class T> 
class Unique_ptr
{

  public:
    Unique_ptr(T* a = NULL)
    :a_(a)
    {}
    
    ~Unique_ptr()
    {
      if(a_)
        delete a_;
    }

    T& operator*()
    {
      return *a_;
    }

    T* operator->()
    {
      return a_;
    }
    
  private:
    //防止拷贝 和 赋值 ，我们将其定义为私有成员函数，并且只做声明，不实现
    Unique_ptr(const Unique_ptr<T>& source);
    Unique_ptr& operator = (Unique_ptr<T>& target);
    
    //c++11  新玩法 ，在 函数后面添加  = delete
    T* a_;
};

int main()
{

  return 0;
}
