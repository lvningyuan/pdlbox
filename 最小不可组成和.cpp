[编程题]求正数数组的最小不可组成和
热度指数：1034时间限制：C/C++ 1秒，其他语言2秒空间限制：C/C++ 32M，其他语言64M

给定一个全是正数的数组arr，定义一下arr的最小不可组成和的概念： 1，arr的所有非空子集中，把每个子集内的所有元素加起来会出现很多的值，其中最小的记为min，最大的记为max； 2，在区间[min,max]上，如果有一些正数不可以被arr某一个子集相加得到，那么这些正数中最小的那个，就是arr的最小不可组成和； 3，在区间[min,max]上，如果所有的数都可以被arr的某一个子集相加得到，那么max+1是arr的最小不可组成和； 举例： arr = {3,2,5} arr的min为2，max为10，在区间[2,10]上，4是不能被任何一个子集相加得到的值中最小的，所以4是arr的最小不可组成和； arr = {3,2,4} arr的min为2，max为9，在区间[2,9]上，8是不能被任何一个子集相加得到的值中最小的，所以8是arr的最小不可组成和； arr = {3,1,2} arr的min为1，max为6，在区间[2,6]上，任何数都可以被某一个子集相加得到，所以7是arr的最小不可组成和； 请写函数返回arr的最小不可组成和。
C++11(clang++ 3.9)重置

class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
        int Min =arr[0];
        int Max =0;
        for(int i=0; i< len; ++i)
        {
            if(Min > arr[i])
                Min = arr[i];
            Max += arr[i];
        }
        
        vector<int> dp(Max+1,0);
        for(int i =0; i<len; ++i)
        {
            for(int j=Max; j>=arr[i]; --j)
            {
                if(dp[j-arr[i]] + arr[i] > dp[j])
                    dp[j] = dp[j-arr[i]] + arr[i];
            }
        }
        
        for(int i=Min; i<= Max; ++i)
        {
            if(i != dp[i])
                return i;
        }
        return Max + 1;
    }
};