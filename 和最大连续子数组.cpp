

53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

方法一

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];//目标和
        int tmp = nums[0];//临时和
        for (int i =1; i< nums.size(); ++i)
        {
            tmp += nums[i];//计算当前的和
            if(tmp < nums[i])//上次和为负数，则抛弃上次和
                tmp = nums[i];//让当前数作为新值
            max = tmp > max ? tmp : max;//判断是否需要更新最大值
            if(tmp < 0)//若当前和为负, 让下一个值作为新和的起点
                tmp = 0; 
        }
        return max;
    }
};


方法二：
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int tmp = nums[0];
        for (int i =1; i< nums.size(); ++i)
        {
            if(tmp  > 0)
                tmp += nums[i]; 
            else
                tmp = nums[i];
            
        max = tmp > max ? tmp : max;  
        }
        return max;
    }
};