找假币



分析： 二分显然不如三分   
      三分问题来了： 有余数， 没余数？   一定得找出 ，就得考虑最坏情况。
	那么 每次%3有余数。-->最坏则  x = x/3 + (x%3 > 0)， 


// write your code here cpp
#include <iostream>


using namespace std;

int main()
{
    int x;
    int n=1;
    while(cin>>x)
    {
        if(x == 0) return 0;
        else if(x ==1)
            cout<<0<<endl;
        else 
        {
         while(x > 3)
        {
            x = (x%3==0) ? x/3 : (x/3)+1;
            ++n; 
        }
        cout<<n<<endl;
        n = 1;
        }
    }
}