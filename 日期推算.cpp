给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出描述:
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。


#include  <iostream>
using namespace std;

class Date
{
    public:
    
    Date(int year, int month, int day)
        :year_(year)
         ,month_(month)
         ,day_(day)
        {}
    
  void nextNday(int n)
  {
      int Day[13]={0, 31,28, 31, 30, 31,30, 31, 31,30 ,31 ,30, 31};
      
      while(n)
      {
          if( (year_ % 4 == 0 && year_ % 100 != 0 ) || year_ % 400 ==0)
                Day[2] =29;
          else  
              Day[2] = 28;
          
           if(day_ == Day[month_])
          {
              month_++;
              day_ = 1;
              if(month_ == 13)
              {
                  year_++;
                  month_ =1;
              }
              n--;
          }
          else
          {
             day_++;
              n--;
          }
      }
      if (month_ < 10)
          cout<<year_<<"-0"<<month_;
      else 
          cout<<year_<<"-" <<month_;
      if(day_ < 10)
          cout<<"-0"<<day_<<endl;
      else
          cout<<"-" <<day_<<endl;
  }
    
    private:
    
    int year_;
    int month_;
    int day_;
    
};


int main()
{
    int m;
    cin>>m;
   while(m)
  {
    int year;
    int month;
    int day;
    int n;
    
    
    cin>>year; 
    cin>>month;
    cin>>day;
    cin >>n;
       
    Date d(year, month, day);
    d.nextNday(n);
   
    m--;
   }
    return 0;
}






2

题目描述
根据输入的日期，计算是这一年的第几天。。

详细描述：

输入某年某月某日，判断这一天是这一年的第几天？。

 

 

接口设计及说明：

 /*****************************************************************************
 Description   : 数据转换
 Input Param   : year 输入年份
                Month 输入月份
                Day 输入天
                    
 Output Param  :
 Return Value  : 成功返回0，失败返回-1（如：数据错误）
 *****************************************************************************/
 public static int iConverDateToDay(int year, int month, int day)
 {
     /* 在这里实现功能，将结果填入输入数组中*/ 
     return 0;
 }
 
 /*****************************************************************************
 Description   : 
 Input Param   :
                    
 Output Param  :
 Return Value  : 成功:返回outDay输出计算后的第几天;
                                           失败:返回-1
 *****************************************************************************/
 public static int getOutDay()
 {
  return 0;
 }

 

 

 

 

输入描述:
输入三行，分别是年，月，日

输出描述:
成功:返回outDay输出计算后的第几天;
                                           失败:返回-1

示例1
输入
复制
2012
12
31
输出
复制
366

#include <iostream>

    
using namespace std;

class Date
{
    public:
        Date(int year, int month, int day)
            :_year(year)
             ,_month(month)
             ,_day(day)
            {}
    
  void outDay()
   {
       int a[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
       int sum =0;
       //判断是否是闰年
       if((_year % 4 ==0 && _year % 100 != 0) || _year %400 ==0)
       {
           a[2] +=1;//闰年2月多一天1
       }
       
       _month -=1;
       sum += _day;
       while(_month)
       {
           sum += a[_month];
           --_month;
       }
       cout<<sum<<endl;
   }
    
    
    private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    int year;
    int month;
    int day;
    cin>>year;
    cin>>month;
    cin>>day;
    if(year < 0 || month < 1 || day < 0)
        return -1;
    
    Date d(year,month,day);
    
   d.outDay();
    return 0;
}



3

题目描述
给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出描述:
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
示例1
输入
复制
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
输出
复制
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01




#include <iostream>

using namespace std;

void getDate(int year ,int n)
{
    int Day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if((year % 4 ==0 && year % 100 != 0 ) || year %400 == 0)
    {
        Day[2] += 1;
    }
    int month =1;
    int day = 0;
    while(n)
    {
        if(n > Day[month])
        {
            n -= Day[month];
            month++;
        }
        else 
        {
            day = n;
            n = 0;
        }
    }
    if(month < 10)
        cout<<year<<"-0"<<month;
    else
        cout<<year<<'-'<<month;
    if(day < 10)
        cout<<"-0"<<day<<endl;
    else
        cout<<'-'<<day<<endl;
}

int main()
{
    int year;
    cin >> year;
    int n;
    cin>>n;
    getDate(year,n);
    return 0;
}
