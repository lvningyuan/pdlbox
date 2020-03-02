#include <map>
#include <string>
#include <iostream>

using namespace std;

void TestMap()
{
  std:: map<std::string, std::string> m;
  //   1  向map中插入元素     pair<T, T>----键值对 
  m.insert( std::pair<std::string, std::string>("peach", "桃子") );

  //  2  插入元素 ，make_pair的键值对
  m.insert(make_pair("banana", "香蕉"));

  //  3  插入元素  operator【】  插入
  //
  //  operator【】  原理    先利用key  构造一个key_value 键值对  ， 再底层调用 insert函数
  //                原来map  中 键不存在----插入成功：  返回插入位置的迭代器，
  //                原来map  中 键存在  ----插入失败，  返回原来存在位置迭代器
  //                最后 operator 【】  --- 将insert函数返回的迭代器中的     value的引用 返回;
  //
  //                这里 将返回的<"apple", "">  返回的""引用修改为 "苹果"
  m[ "apple" ] = "苹果";

  //  4   at  
  //  key  不存在 则程序抛出异常 ， 存在 ，返回对应value的引用
  //  m.at(" waterme")  ="水蜜桃";

      cout<<"m 的内的个数" << m.size()<< endl;


  //遍历输出m中的 内容
  for(auto e : m)
  {
    cout<<e.first<<"-----"<<e.second<<endl;
  }
    


    //map 内的键值对是唯一的
    // make_pair   pair  返回值 均为 pari 类型，<iterator , bool>
   auto ret = m.insert(pair<string, string> ("black","黑色"));//  insert 函数返回 value_type  类型的迭代器 ，
   if( ret.second )//ret.sevond == true  即 原本不在 ，并插入成功 
   {
      cout<<"black  ---  黑色 不在 map 中， 并进行插入"<<endl;
   }

   else
   {
     cout<<"black --- 黑色  在 map 中 ，所以插入失败"<<endl;
   }

    //删除 erase
    m.erase("apple");

    if(m.count("apple")  == 1)
        cout<<"apple 还在"<<endl;
    
    cout<<"apple"<<"被吃了"<<endl;

    cout<<"m中还有"<<m.size()<<"个键值对"<<endl;
}

int main()
{

  TestMap();

  return 0;
}



