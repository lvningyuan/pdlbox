方案一：

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> DP(array.size());
        DP[0] = array[0];
        int ret = DP[0];
        for(int i=1; i<array.size(); ++i)
        {
            //获取所有位置的最大值
            DP[i] = max(DP[i-1]+array[i], array[i]);
            //记录整体的最大值
            if(DP[i] > ret) ret = DP[i];
        }
        return ret;
    }
};




方式二：


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
              int Max = array[0];
        int cur = array[0];
        
        for(int i=1; i<array.size(); ++i)
        {
            cur = max(cur + array[i],array[i]);
            Max = max(Max, cur);
        }
        return Max;
    }
};