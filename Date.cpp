#include <iostream>

using namespace std;

class Date
{
  public:
    int  GetMonthDay()
    {
      int day[13] ={0, 31 ,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if(month_ == 2  &&  (( year_ % 4 == 0 && year_ %100 != 0 ) ||  year_ % 400 != 0 ) )
        return day[2] + 1;

      return day[month_];
    }


    Date(int year =1990 ,int month = 1, int day = 1)
      :year_(year)
       ,month_(month)
       ,day_(day)
  {
    cout<<"Date()"<<endl;
  }

    Date(const Date& d)
    {
      year_  = d.year_;
      month_ = d.month_;
      day_   = d.day_; 
    }

    Date&  operator +(int n )
    {
      while(n)
      {
        if(day_ + n <= GetMonthDay())
        {
          day_ += n;
          break;
        }

        n = n -  GetMonthDay() + day_ -1;
        day_ = 1;
        if(month_ < 12)
          month_++;
        else 
        {
          month_ =1;
          year_ ++;
        }
      }
      return *this; 
    }

    Date&  operator -(int n )
    {
      while(n)
      {
        if(day_ - n >= 1)
        {
          day_ -= n;
          return *this;
        }

        if(month_ > 1)
        {
          month_ --;
        }
        else 
        {
          month_ = 12;
          year_ --;
        }
        day_ += GetMonthDay();
      }
      return *this;
    }

    Date&  operator ++()
    {
      if(day_ == GetMonthDay() )
      {
        day_ = 1;

        if(month_ == 12)
        {
          month_ = 1;
          year_ ++  ;
        }
        else 
          month_ ++;
      }
      else 
        day_++;
      return *this;
    }

    Date&  operator --()
    {
      if(day_ == 1)
      {
        month_ --;

        if(month_ == 0)
        {
          year_ --;
          month_ = 12;
        }
        day_ = GetMonthDay();
      }
      else 
        day_ --;
      return *this;
    }

    Date&  operator =(const Date& d)
    {
      year_  = d.year_;
      month_ = d.month_;
      day_   = d.day_;

      return *this;
    }

    bool   operator == (const Date& d)
    {
      return year_ == d.year_ && month_ == d.month_ &&  day_ == d.day_;
    }

    bool   operator !=(const Date& d)
    {
      return year_ != d.year_ || month_ != d.month_ || day_ != d.day_;
    }

    bool   operator <=(const Date& d)
    {
      if(year_  > d.year_)
        return false;
      if(month_ > d.month_)
        return false;
      if(day_   > d.day_)
        return false;

      return true;
    }

    bool   operator >=(const Date& d)
    {
      if(year_  < d.year_)
        return false;
      if(month_ < d.month_)
        return false;
      if(day_   < d.day_)
        return false;

      return true;
    }

    bool   operator < (const Date& d)
    {
      if(year_  >= d.year_)
        return false;
      if(month_ >= d.month_)
        return false;
      if(day_   >= d.day_)
        return false;

      return true;
    }

    bool   operator >(const Date& d)
    {
      if(year_  <= d.year_)
        return false;
      if(month_ <= d.month_)
        return false;
      if(day_   <= d.day_)
        return false;

      return true;

    }

 void GetDate()
 {
   cout<<"year :"<<year_<<"month :"<<month_<<"day :"<<day_<<endl;
 }

    ~Date()
    {
      cout<<"~Date()"<<endl;
    }

  private:
    int year_;
    int month_;
    int day_;
};







int main()
{
  Date d(2020 ,3,16);
  d.GetDate();
  Date d1(d);
  d1.GetDate();

  d1.operator++();
  d1.GetDate();
  
  d1.operator+(30);
  d1.GetDate();
  
  d1.operator-(30);
  d1.GetDate();
  return 0;
}
