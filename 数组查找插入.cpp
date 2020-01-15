方法一 ：  class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int len =nums.size();
     //nums.resize(len+1);
     for(int i = 0 ; i<len ;++i)
     {
         if(nums[i] == target)
         return i;

         if( nums[i] > target)
        {
            nums.insert(nums.begin()+i,target); 
             return i;
        }
     }

     ／／nums.push_back(target);
     return len;
    }
};


方法二：class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int  len = nums.size();
     int left = 0;
     int right = len ;//左闭右kai
     while(left<right)
     {
         int mid = left + ( (right - left) >>2);
          if(nums[mid] == target  )
          return mid;
          if(nums[mid] > target)
        {
            right =mid ;
        }
          if(  nums[mid] < target )
          {
              left = mid +1;
          }
     } 
     return left;
    }
};