#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
      unordered_map<string,int> mp;
      string key[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
      int  values[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};

      int n = sizeof(values) / sizeof(int);
      int x  = 0;
      for(int i=0; i < n; ++i)
      {
        mp[key[i]] =values[i];//创建哈希map 键值对
      }
      string tmp;
     // n = s.size();  正确做法，让此行生效，屏蔽此行是因为出错分析调试
      for(int i = 0; i < n; ++i)
      {
        tmp = s[i];
        if(i+1 == n)//处理边界
        {
          cout<<"当前  i :"<<i<<endl<<"当前map 匹配到的值"<<mp[tmp]<<"当前x 值"<<x<<endl;
          x += mp[tmp];
          cout<<"处理后x 值"<<x<<endl;
        }

        else
        {
          tmp += s[i+1];
          if(mp.find(tmp) != mp.end())
          {
            cout<<"当前 i :"<<i<<endl<<"当前map 匹配到的值"<<mp[tmp]<<"当前x 值"<<x<<endl;
            x += mp[tmp];
            ++i;
            cout<<"处理后x 值"<<x<<endl;
            cout<<"组合处理后 i "<<i<<endl;
          }

          else 
          {
            tmp.resize(1);
            cout<<"当前  i "<<i<<endl<<"当前map 匹配到的值"<<mp[tmp]<<"当前x 值"<<x<<endl;
            x += mp[tmp];
            cout<<"处理后x 值"<<x<<endl;
          }
        }
      }
      return x;
    }
};

int main()
{
  Solution s;
  int x =  s.romanToInt("DCXXI");
  cout<<x<<endl;
  return 0;
}
