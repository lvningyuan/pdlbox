面试题42. 连续子数组的最大和
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。



思路：动态规划 一维数组 + 一个变量。解决


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     vector<int> ret(nums.size(),0);
     int Max = nums[0];
     int len = nums.size();
     ret[0] = nums[0];
     for(int i =1; i < len; ++i)
     {
         ret[i] = ret[i-1] > 0 ? ret[i-1] + nums[i]: max (ret[i-1], nums[i]);  
         Max = max(Max, ret[i]);  
     }
     return Max;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     if(nums.size() == 0)
        return 0;

     int  Max =nums[0];
     int tmp = nums[0];
     for(int i=1; i< nums.size(); ++i)
     {
         //当前数不论正负，+正数必然增大，
         tmp = tmp > 0 ? tmp + nums[i] : max(tmp, nums[i]);
         Max = max(Max ,tmp);
     }
     return Max;
    }
};