


给定一个整数数组（有正数有负数），找出总和最大的连续数列，并返回总和。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int ret = nums[0];
      int tmp =0;
      for(int i=0; i<nums.size(); ++i)
      {
          tmp += nums[i];
          //  if (tmp < 0) tmp =0;
	  ret = max(ret, tmp); 
          if (tmp < 0) tmp =0;
      }
      return ret;
    }
};
