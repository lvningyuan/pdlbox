class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();    
        int len1 =0;
        int k=0;？//保证锌有效元素的下标
        for(int i = 0; i < len; ++i )
       {
           if(nums[i] != val)
          {
            nums[k]=nums[i];
            ++k;
          }
            else
            ++len1; //记录 val元素 个数
       }
       int  newsize =len - len1; 
       nums.resize(newsize);
    return ;
    }
};