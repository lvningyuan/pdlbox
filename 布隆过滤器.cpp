#pragma  once
#include <iostream>
//#include <bitset>
#include <vector>
#include "字符串哈希希算法.cpp"

using namespace std;

template<size_t N>//N  要存储的数据的 最大范围
class Bit
{

  public:
    //位图实现  :底层用比特位实现 ，1byte= 8bit 
    Bit(size_t n = N)
      :v_((n>>3) + 1)//  N>>3 计算出需要映射用的字节数  1字节 右 8 bit  可映射8个 , +1 是为了 防止初始化0个字节
       ,count_(0)
  {}

    ~Bit()
    {}

    void set(size_t num)
    {
      if(num >= N )
        return;//超出位图最大范围

      int index = num >> 3; //找第几个字节
      int which = num % 8;//处于该字节的哪一位
      v_[index] |= (1<<which); //1 右移到which这个比特位 ，再跟这个比特位|运算
      ++count_;
    }

    void reset(size_t num)
    {
      if(num >= N)
        return ;

      int index = num >>3;
      int which = num % 8;
      v_[index] &= ~(1<<which);//1<<which  100000  再取反 01111111  0&任何数 ==0
      --count_;
    }

    size_t size()const //返回位图的大小
    {
      return N;
    }

    size_t count()const    //返回位图中状态为1的个数
    {
      return count_;
    }
    //count也可以用其他方法求，如果没有count_这个成员变量 ，那么 count最好通过哈希的方法去求；  每个字节为一个哈希桶，在网上可以查到哈希桶的初始化  。每个桶中1 的个数 0-7 


    //检测位图中pos位置是否是1
    bool test(size_t pos)
    {

      if(pos >= N)
      {
        cout<<"超过位图大小"<<endl;
        return false; 
      }

      int index = pos >>3;
      int which = pos % 8;

      if( (v_[index] & (1<<which)) != 0 )//安位与  空位补零
      {
        return true;
      }
      else 
        return false;
    }

  private:
    vector<unsigned char> v_;
    size_t count_;
};


template<class N,class T, class H1, class H2 ,class H3, class H4, class H5 >  //T 元素类型
class BL
{
  public:

    BL(size_t size)//size  为bloomFiter中元素的最大范围即个数
      :bl_(5 * size)// 默认用5位做布隆过滤器的状态
       ,count_(0)
  {}

    bool Insert(T& t)
    {
      int totolBites = bl_.size();//N位正常位图的大小，正常位图比特位1 -- 1  映射 ，布隆过滤器5 -1 映射
      int index1 = H1()(t) % totolBites;
      int index2 = H2()(t) % totolBites;
      int index3 = H3()(t) % totolBites;
      int index4 = H4()(t) % totolBites;
      int index5 = H5()(t) % totolBites;

      bl_.set(index1);
      bl_.set(index2);
      bl_.set(index3);
      bl_.set(index4);
      bl_.set(index5);
      ++ count_;
    }

    bool Find (const T& t)
    {
      int totolBites = bl_.size();
      int index1 = H1()(t) % totolBites;
      if( !bl_.test(index1))
        return false;
      int index2 = H2()(t) % totolBites;
      if( !bl_.test(index2))
        return false;

      int index3 = H3()(t) % totolBites;
      if( !bl_.test(index3))
        return false;
      int index4 = H4()(t) % totolBites;
      if( !bl_.test(index4))
        return false;
      int index5 = H5()(t) % totolBites;
      if( !bl_.test(index5))
        return false;

      return true;

    }

    size_t Count()const  //元素个数
    {
      return count_;
    }



  private:
    Bit<100> bl_;
    size_t count_;
};
#if 0

int main()
{

  Bit<100> b;
  b.set(5);
  b.set(4);
  b.set(12);
  cout<<"size  " <<b.size()<<endl;
  cout<<"count 1 : "<<b.count()<<endl;
  return 0;
}

#endif

#if 0
int main()
{

  int a[] {1,2,3,7,4,5,6};
  bitset<100> bt;
  bt.set(1);
  bt.set(3);
  bt.set(a[4]);
  cout<<"状态为1 的数量"<<bt.count()<<endl;
  cout<<"bt位图的大小为"<<bt.size()<<endl;

  bt.reset(3);
  cout<<"复位一个后 ："<<endl;
  cout<<"状态为1 的数量"<<bt.count()<<endl;
  cout<<"bt位图的大小为"<<bt.size()<<endl;
  cout<<"第7个位" <<bt[7]<<endl;

  cout<<"bt位图的大小为"<<bt.size()<<endl;
  return 0;
}

#endif
