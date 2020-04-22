// write your code here cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    
    while(cin>>a>>b)
    {
        int len = b.size();
        int sum=0;
        for(int i=0; i < a.size(); ++i)
        {
            if(a.substr(i,len) == b)
            {
                i += len-1;
                ++sum;
            }
        }
        cout<<sum<<endl;
    }
    
    return 0;
}