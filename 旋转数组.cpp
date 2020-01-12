
右旋k位

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       if(k == 0)
       return ;

       int len = nums.size();
       k= k%len ;
     reverse(nums.begin(), nums.end());
     reverse(nums.begin(), nums.begin() + k);//切记reverse左闭右开区间
     reverse(nums.begin() + k ,nums.end());
       }
};