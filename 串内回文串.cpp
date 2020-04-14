给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。



class Solution {
public:
 void helper(string &s, int i, int j, int &res, int size)
 {
        while (i >= 0 && j < size && s[i] == s[j]) 
         --i,++j,++res;
 }
    int countSubstrings(string s) {

        int size = s.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            helper(s, i, i, res, size);
            helper(s, i, i + 1, res, size);
        }
        return res;
    }
};
