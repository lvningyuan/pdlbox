338. 比特位计数
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1,0);
        for(int i=1; i <= num; ++i )
        {
            int x = i;
            int n=1;
            while(x & x-1)
            {
                ++n;
                x = x & (x-1);
            }
            v[i] = n;
        }
        return v;
    }
};