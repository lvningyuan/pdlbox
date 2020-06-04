class Solution {
private: 
    vector<vector<int>> ret;
    vector<bool> memo;
    void subQuestion(vector<int>& nums, int index){
            if(index == nums.size() && find(ret.begin(), ret.end(), nums) == ret.end()) { //判重
                ret.push_back(nums);
                return ;
            }
            for(int i=index; i<nums.size(); ++i){
                if(i > index && nums[i]==nums[i-1])//不交换
                    continue;
                //当前 index 可以跟 i 可以交换
                swap(nums[i], nums[index]);
	    		subQuestion(nums, index+1);
    			swap(nums[i], nums[index]);//回溯
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        memo = vector<bool>(nums.size(),false);
        if (nums.size() == 0 ) return ret;
        subQuestion(nums, 0);
        return ret;
    }
};