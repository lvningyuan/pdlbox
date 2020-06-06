

给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {

public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int len = nums.size();
        if(len < 2) return false;
        if(k == 0){
            for(int i=1; i<len; ++i)
                if (nums[i]==0 && nums[i-1] ==0)
                    return true;
            return false;
        }

        for(int i=0; i<len; ++i){
            int sum=0;
        for(int j=i; j<len; ++j){
            sum += nums[j];
            if(sum % k == 0 && j-i>=1) return true;
        }
    }
      return false;
    }
};