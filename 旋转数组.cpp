
����kλ

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       if(k == 0)
       return ;

       int len = nums.size();
       k= k%len ;
     reverse(nums.begin(), nums.end());
     reverse(nums.begin(), nums.begin() + k);//�м�reverse����ҿ�����
     reverse(nums.begin() + k ,nums.end());
       }
};