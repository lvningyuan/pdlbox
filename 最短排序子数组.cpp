class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int len = nums.size();
        vector <int > v;
        v = nums;
        sort(v.begin(),v.end());

        int start=0;
        for(int i=0; i<len ; ++i)
        {
            if(nums[i] != v[i])
            {
                start =i;
                break;
            }
        }
        int end=0;
        for(int i =len-1; i>=0; --i)
        {
            if(nums[i] != v[i])
            {
                end=i;
                break;
            }
        }
        return  end==start? 0 : end - start +1;
    }
};