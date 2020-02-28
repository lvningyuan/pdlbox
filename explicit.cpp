#include <iostream>


class A
{
  public:
 explicit  A(int n)
   :data_(n)
 {}
  private:
    int data_;
};


int main()
{
  A a(1);
  

 // 构造函数加了 explicit  意味着 不能进行 隐式类型转换，即 不会先构造一个临时对象  A tmp（2）; A b(tmp);
  // A b =2;
  
  return 0;
}
