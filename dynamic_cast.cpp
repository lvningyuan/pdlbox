#include <iostream>

using namespace std;

class A
{
  public:
   virtual void f(){}; 
};

class B :public A 
{};//因为派生类并没有重写虚函数，所以 不属于多态，所以可以为静态类型转换


void fun(A* pa)
{
  B* p1  = static_cast<B*> (pa);
  A* p2  = dynamic_cast<A*> (pa);
  cout<<"p1 is "<<p1<<endl<<"p2 is"<<p2<<endl;
}

int main()
{
  A a;
  B b;
  fun(&a);
  fun(&b);
  return 0;
}
