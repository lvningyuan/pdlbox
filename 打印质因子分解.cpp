#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void isPrime(vector<int>& v)
{
    v.push_back(2);
    v.push_back(3);
    for(int i=4; i <= 1000000; ++i)
    {
        int flag =0;
        for(int j=2; j< pow(i,0.5); ++j)
        {
            if(i % j == 0)
            {
                flag =1;
                break;
            }        
        }
        if(flag != 1)
        {
            v.push_back(i);
        }
    }
}

int main()
{
    vector<int> v;
    isPrime(v);
    
    int  x;
    while(cin>>x)
    {
        string tmp = "";
        char a[10] ={0};
        cout<<x<<" = ";
        for(int i=0; i<v.size(); ++i)
        {
            while(x >= v[i] && x%v[i] == 0)
            {
      
                sprintf(a,"%d",v[i]);
                string t = a;
                tmp += t;
                tmp += " * ";
                x /= v[i];
            }
        }
        tmp = tmp.substr(0,tmp.size() -3);
        cout<<tmp<<endl;
    }
    return 0;
}