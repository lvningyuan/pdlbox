class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();    
        int len1 =0;
        int k=0;��//��֤п��ЧԪ�ص��±�
        for(int i = 0; i < len; ++i )
       {
           if(nums[i] != val)
          {
            nums[k]=nums[i];
            ++k;
          }
            else
            ++len1; //��¼ valԪ�� ����
       }
       int  newsize =len - len1; 
       nums.resize(newsize);
    return ;
    }
};