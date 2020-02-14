#include <iostream>
#include <stdlib.h>
using namespace std;
void JieCheng(int num);

int a[100000],m;        //a[]为被乘数及结果存放位置
//m为位数
int main()
{

  int num;
  cin>>num; 
   m=1;//结果的位数
  a[0] =1;


  JieCheng(num);
  return 0;
}




void JieCheng(int num)
{
 
  int num2 =0;
  for(int i=2; i<=num; i++)    //i为乘数,,num2用于存放进位。
  {
  
    int temp =0;
    for(int j=0; j<m; j++)    //乘数各位a[j] *i,
      {
        temp=a[j]*i+num2;
        a[j] = temp % 10;
        num2 = temp / 10;
      } 
  
    while(num2)
    {
      a[m++]=num2 % 10;//因为位数始终比下表大一，所以 m++
      num2 /= 10;
    }
  
  }

  for(int j=m-1; j>=0; --j)
    cout<<a[j];

  cout<<endl;

}
