## 哈希+ 双指针
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。


不要光看两个while
时间复杂度还是O(n)的



```cpp
class Solution {
public:
    string reverseVowels(string s) {
     vector<int> v(256,0);
     v['a']=1; v['A']=1;
     v['e']=1; v['E']=1;
     v['i']=1; v['I']=1;
     v['o']=1; v['O']=1;
     v['u']=1; v['U']=1;
     int r = s.size()-1;
     int l =0;
     char tmp;
     
     while(l < r)
     {
        while(l < r && v[s[l]] != 1) ++l;  
        while(l < r && v[s[r]] != 1) --r;
        if(v[s[l]] == v[s[r]] && v[s[l]] ==1 && s[l] != s[r])
        {
            tmp = s[l];
            s[l]= s[r];
            s[r]= tmp;
        }
        ++l;
        --r;
     }
     return s;   
    }
};