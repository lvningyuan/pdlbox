class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1 = nums1.size();
        for(int i =len1 - 1; i >= 0; --i)
        {
            if(nums1[i] == 0)
            --len1;
            else
            break;
        }
         int len2 = nums2.size();
         for(int i =len2 - 1; i >= 0; --i)
        {
            if(nums2[i] == 0)
            --len2;
            else
            break;
        }
       
       for(int i=0; i < len2; ++i)
       {
           nums1[len1] =(nums2[i]);
           ++len1; 
       }
       len1 =len1 + len2;
       sort(nums1.begin(),nums1.end());
    }
};