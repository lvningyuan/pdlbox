96. 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？


class Solution {
public:
    int numTrees(int n) {
        if (n<= 0 )return 0;
        vector<int>dp(n+1); //0  取不到
        dp[0] = dp[1] =1;
        for(int i=2; i<=n; ++i)//当前的
        for(int j=1; j<=i; ++j)//当前的不同组合数量
            dp[i] += dp[j-1] * dp[i-j];
        
        return dp[n];
    }
};