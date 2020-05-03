
## 最长上升子序列数

题目描述：

一个数的序列bi，当b1

输入描述：

第一行输入序列的长度N(1<=N<=1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。

输出描述：

输出最长上升子序列的长度

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m;
     while(cin>>m)
    {
         int n;
         vector<int> v;
        while(m)
        {
            cin>>n;
            v.push_back(n);
            --m;
        }
        vector<int> a(v.size(),1);
         int Max = 1;
         for(int i=0; i<v.size(); ++i)
         {
             for(int j=0; j<i; ++j)
             {
                 if(v[i] > v[j])
                 {
                     a[i] = max(a[i],a[j]+1);//动态更新，类似于大问题化小
                     Max = max(Max, a[i]);
                 }
             }
         }
         cout<<Max<<endl;
    }
        return 0;
}
```
