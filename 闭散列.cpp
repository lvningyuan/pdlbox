#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;




//  闭散列






enum State{  EMPTY, EXIST, DELETE };//三种状态 


//为解决不是所有的情况况都适用除留余数法，我们写一个通用的方法 -----仿函数类
template<class  T>
class Atoi
{
  public:
   size_t  operator() (const T& val)//判断有没有启用不适合除留余数法类型 的解决方案
    {
      
      const char* str = val.c_str();
      unsigned int seed =131;//  31 ,  131 , 1313, 13131, 131313 .....
      unsigned  int hash = 0;
      while(*str)
      {
        hash = hash * seed +(*str++);
      }
      return (hash & 0x7FFFFFFF);
    }

};


template <class K, class V ,class HF>
class HashTable
{
  struct Elem  //每个元素都是一个
  {
    State state_;
    pair<K, V> val_; 
  };

  HashTable(const int capacity = 3)
  :ht_(capacity)  // 开辟空间为3的vector哈希表     //初始化列表类类型对象 ，该类没有默认的构造函数
  ,size_(0)   // 哈希表初始个数 初始化为0
  {
    for(int i =0; i<capacity; ++i)
    {
      ht_[i].state_ = EMPTY;// 哈希表初始化 所有地址  为空
    }
  }

  public: 
  
   const static unsigned int PrimeCount = 8; 
   const unsigned int PrimeList[PrimeCount] ={ 53ul, 97ul, 103ul, 398ul, 769ul, 1543ul,3079ul,6151ul };
  size_t GetNextPrime()
  {
      for(int i =0; i<PrimeCount; ++i)
      {
        if(ht_.capacity() < PrimeList[i])
        {
          return PrimeList[i];
        }
      }
      return PrimeList[PrimeCount -1];
  }
  
  
  void Swap(HashTable<K, V, HF>& newHT )
  {
      swap(newHT);//vector 内部的 swap更高效，实质为交换三个值针就ok  start  finish  end_of_shorage
      swap(ht_.size_, newHT.size_);
  }
  
  void Check_Capacity()
  {
    //这里 可以设置 增容机制
    int a =  size_ *10 / ht_.capacity();
    if(a >= 7)//需要扩容   扩容采用替换的思想
    {
      HashTable <K, V ,HF> newHT (GetNextPrime());
      for(size_t i=0; i<ht_.capacity(); ++i )
      {

        //因为重新插入另一个哈希表时算法不一致  即 哈希函数的 capacity不一致，需要重新计算插入，所以，DELETE掉的元素可以忽略掉了
        if(ht_[i].state_ == EXIST)
          newHT.Insert(ht_[i].val_);
      }
    //newHT  替换 原有的ht_
      Swap(newHT);
    }
  }





  //我们知道 哈希表是动态的   是不能存在被插入满的，所以一定能找到EMPTY状态的位置
  bool Insert(const pair<K,V> & val) 
  {
    //首先判断 哈希表需不需要增容,
      Check_Capacity();

      // 求  hashdAddr
      size_t hashAddr = HashAddr(val.first);
      //判断是否冲突
     
      while(ht_[hashAddr].state_ != EMPTY)
      {
        //  存在相同元素 ，返回插入失败  
        if(ht_[hashAddr].state_ == EXIST && ht_[hashAddr].val.first == val.first)//该位置有元素 并且就是要插入的元素
        {
          return false;
        }
        //  存在DELETE 元素
        else if (ht_[hashAddr].state_ == DELETE)
        {
          ht_[hashAddr].val_ = val;
          ++size_;
          return true;
        }
        //否则 线性探测
        ++hashAddr;

        //走到结尾没找到 回头接着找
        if(hashAddr == ht_.capacity())
          hashAddr = 0;
      }

      ht_[hashAddr].state_ = EXIST;
      ht_[hashAddr] = val;//存入该键值对
      ++size_; 
      return true;
  }


  //STL 中的find  是返回迭代器类型的 ，现在我们先写成int类型 找到，返回地址下表，没找到返回-1
int Find(const K& key)//查找关键码
{

  int startaddr  =  HashAddr(key);
      while(ht_[startaddr].state_ != EMPTY)
      {
        if(ht_[startaddr].state_  ==EXIST  &&  ht_[startaddr].val.first == key )
          return startaddr;

        ++startaddr;
        if(startaddr == ht_.capacity())
          startaddr = 0;
      }
  return -1;
}

bool Erase(const K& key)
{
   int ret = Find(key); 
   if(ret == -1)
   {
     //cout<<"哈希表中不存在该关键码"<<endl;
     return false;
   }
  //否则 包含 
  //注意 闭散列法不能直接删 ，否则导致其他关键码可能无法查询
  ht_[ret].state_ = DELETE;
  --size_;
  return true;
}



  private:
    //提供一个哈希函数  这里暂时提供除留余数法（但要清楚，并不是所有的情况除留余数法都适用）
    size_t HashAddr ( const K& key )const 
    {
        return HF() (key)  % size_;//HF为一种处理机制，保证一定可以适用除留余数法
    }
  private:
    vector<Elem>  ht_;// 底层存储用的 哈希表
    size_t size_; //记录有效元素的个数

};
