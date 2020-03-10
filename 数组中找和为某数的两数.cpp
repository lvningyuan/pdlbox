给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    //思路，创建一个map，边查找，边初始化map 
    vector<int> twoSum(vector<int>& nums, int target) {
       int len =nums.size();
       unordered_map<int,int> dict;
       for(int i=0; i<len; ++i )//因为返回下表，所以不能用范围for
       {
           if(dict.find(target - nums[i]) != dict.end())//找到，返回位置迭代器（指针）
           //所以 找到时，前边的的数据肯定已经出现在map中了
            return {dict[target-nums[i]],i};

            dict[nums[i]] = i;//没找到该数据把位置加载到map中
       }
       return {};//初始化一个空的vector
    }
};