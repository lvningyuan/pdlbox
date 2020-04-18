三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-steps-problem-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int waysToStep(int n) {
    vector<long long int> dp;
    dp.resize(n+4, 0);
    dp[0] =0;
    dp[1] =1;
    dp[2] =2;
    dp[3] =4;
    if(n <= 3)
     return dp[n];

    for(int i=4; i <= n; ++i )
    {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        dp[i] %= 1000000007;
    }
    return dp[n];
    }
};


方法二：


class Solution {
public:
    int waysToStep(int n) {
    if(n < 3)
        return n;
    if (n == 3 )
        return 4;

    long long int dp1 = 1;
    long long int dp2 = 2;
    long long int dp3 = 4;

    long long int ret =0;    
    for(int i= 4; i <= n; ++i)
    {
        ret = dp1 + dp2 + dp3;
        dp1 = dp2;
        dp2 = dp3;
        ret %= 1000000007;
        dp3 = ret;
    }
    return ret;
    }
};