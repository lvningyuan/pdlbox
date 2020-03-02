#include <iostream>
#include <set>

using namespace std;


void TestSet()
{
    
  set<int> s1;
  cout<<"s1 的默认大小"<<sizeof(s1)<<endl;
  //用数组中的元素构造 set  
  int  a[] ={5,6,5,6,4,7,8,3,9,5,6,4,7,8,3,34,5,2,3,454,4,56,7,8,9,8,7,6,5,4,3,56,4,56,76,78,9,0,4,3,2,3,54,4,5,6,78,8,5,4,3,2,3,4,5,6,7,8};

  //区间构造
  set<int> s(a, a + sizeof(a) / sizeof(int) );
  cout<<"set 的 容量"<<s.size()<<endl;
  

  //set  遍历打印一下 set  其实存储的是 value_value  所以 ，里面的键值对 对象不存在访问方法
  for(auto& e :s )
  {
    cout<<e;
  }
  cout<<endl;

  for(auto it = s.rbegin(); it != s.rend(); ++it)  //反向迭代器
  {
      cout<<*it<<endl;
  }

  cout<<"3 的 个数"<<s.count(3)<<endl;
  cout<<"set  s 的大小"<<sizeof(s)<<endl;

}


int main()
{
  TestSet();
  return 0;
}
