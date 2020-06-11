class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
    if(amount < 0) return -1;
    if(amount == 0) return 0;
    if(coins.size()==0) return -1;
    sort(coins.begin(), coins.end());
    vector<int> dp(amount+1, INT_MAX/2);
    dp[0] = 0;

	//DP ：  类似于01. 背包的变种
    for(int i=1; i<=amount; ++i)
   	 for(int j=0; j<coins.size() && i>=coins[j]; ++j){
    	    dp[i] = min(dp[i-coins[j]]+1, dp[i]);
    }
    if(dp[amount] >= INT_MAX/2) return -1;
    return dp[amount];
    }
};

//贪心算法： 是不可取的 ：  12 = 9 + 1 + 1 +1.  12 = 8 + 4. 因此 贪心不可取 
			




//递归解法：  超出时间限制


/*
class Solution {
private:
    bool dfs(vector<int>& coins, int amount, int& ret, int index){
        if(amount == 0) 
             return true;
        if(index ==coins.size()) 
             return false;
        int  tmp = INT_MAX;
        int  tmp_ret = 0;
        bool flag = false;
        for(int i=index; i<coins.size(); ++i){
            if(amount < coins[i]) continue;
            if(dfs(coins, amount-coins[i], tmp_ret, i)){
                ++tmp_ret;
                flag = true;
                tmp = min(tmp, tmp_ret);
                tmp_ret =0;
            }
        }
        ret = tmp;
        return flag;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <0 || coins.size()==0) return -1;
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end(), [&](int a, int b){
            return a > b;
        });
        int ret =0;
        bool flag = false;
        if( dfs(coins, amount, ret, 0) )
             return ret;
        return -1; 
    }
};

*/