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
    n = s.size();
    for(int i = 0; i < n; ++i)
    {
        tmp = s[i];
        if(i+1 == n)//处理边界
        {
            x += mp[tmp];
        }
        else
        {
            tmp += s[i+1];
            if(mp.find(tmp) != mp.end())
                {
                    x += mp[tmp];
                    ++i;
                }
                else 
                {
                    tmp.resize(1);
                    x += mp[tmp];
                }
        }
    }
    return x;
    }
};