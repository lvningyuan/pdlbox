����һ���������͵�����?nums�����дһ���ܹ��������顰�����������ķ�����

���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�

������鲻����������������ô����Ӧ�÷��� -1����������ж��������������ô����Ӧ�÷��������ߵ���һ����

ʾ�� 1:

����: 
nums = [1, 7, 3, 6, 5, 6]
���: 3
����: 
����3 (nums[3] = 6) �������֮��(1 + 7 + 3 = 11)�����Ҳ���֮��(5 + 6 = 11)��ȡ�
ͬʱ, 3 Ҳ�ǵ�һ������Ҫ�������������
ʾ�� 2:

����: 
nums = [1, 2, 3]
���: -1
����: 
�����в��������������������������


class Solution {
public:
int leftSum(int x,vector<int>& nums)
{
    int ret =0;
    for(int i =0; i<x; ++i)
    {
        ret += nums[i];
    }
    return ret;
}

    int pivotIndex(vector<int>& nums) {
        int len =nums.size();
        int addsum=0;
        for(int i=0; i<len; ++i)
            {
                addsum += nums[i];
            }
        for(int i=0; i <len; ++i)
           {
           if(addsum - nums[i]  == 2 * leftSum(i,nums))
            return i;
           }
        return -1;
    }
};