// write your code here cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void isPrimary(vector<int>& v)
{
    int n = 4;
    v.push_back(2);
    v.push_back(3);
    while(n <= 100000)
    {
        int flag =0;
        for(int i=2; i <=(int)pow(n,0.5); ++i)
        {
            if(n % i == 0)
            {
                flag =1;
                break;
            }
        }
        if(flag ==0 )
            v.push_back(n);
        ++n;
    }
}


int main()
{
    vector<int> v;
    isPrimary(v);
    int x;
    while(cin >> x)
    {
        int ret = 0;
        for(int i =0; i<v.size(); ++i)
        {
            int flag =0;
         while( x >= v[i] && x % v[i] == 0)
         {
             flag =1;
             x /= v[i];
         }
            if(flag ==1) ++ret;
            if(x < v[i]) break;
        }
        cout<<ret<<endl;
    }
    return 0;
}