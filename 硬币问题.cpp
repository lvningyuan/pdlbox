硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

class Solution {

/*
回溯法 （超时） ：  函数压栈开销大
class Solution {
    vector<int>candidates={1,5,10,25};
public:
    int waysToChange(int n) {
        int ans=0;
        // sort(candidates.begin(), candidates.end());
        vector<int>cur;
        dfs(ans, n, n,cur);
        return ans;
    }

    //cur数组专门用于动态判断是否出现重复 6--1+5    6--5 + 1
    //      不就重复了吗？  所以得开辟数组进行保存
    //      所以还得开辟 数组进行保存，防止出现相同的划分
    void dfs(int &ans, int target, int left,vector<int>&cur){
        if(left==0) {
            ans=(ans+1)%1000000007;
            return;
            }
        for(int i=0;i<candidates.size();i++){
            if(candidates[i]>left)
                break;
            if(cur.size()==0||candidates[i]>=cur.back()){
                //防止重复组合
            cur.push_back(candidates[i]);
            dfs(ans, target, left-candidates[i], cur);
            cur.pop_back();
            }
        }
    }
};
*/

//DP 01  背包的思想
int a[4] ={1,5,10,25};
public:
    int waysToChange(int n){
    vector<int>dp(n+1);

    //因为硬币是无限的 ，那么对于一个n来说，可以先将一个硬币/两个/n个  的方案算出来

    dp[0] =1;
    for(int i=0; i<4; ++i){ 
        int tmp = a[i];
        for(int j=tmp; j<=n; ++j)
            dp[j] = (dp[j] + dp[j-tmp]) % 1000000007; 
                    // +=是因为多种组合
    }
    return dp[n];
    }
};