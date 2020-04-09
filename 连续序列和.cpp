
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3




解答：  暴力肯定可以， 但大量调用肯定效率不行，为了一劳永逸，我们采用哈希的思想。

要注意的是从i 到 j。是左闭右开的区间哦

class NumArray {
public:
    vector<int> predo;

    NumArray(vector<int>& nums) {
        predo.resize(nums.size() + 1, 0);
        for(int i=1; i <= nums.size(); ++i)//因为每次用i-1
        {     
            //1  防止大量调用该接口，我们可以提前算好，来的时候不再每次时间复杂度为O(N)， 类似于哈希map的思想

            //2 牺牲一个空间就可以使表达式一直成立了
            //否则从 0 开始没法加，因为不存在前一个数
            // 这导致我们每次需要的前N项和保存在了第n+1项的位置
            predo[i] = predo[i-1] + nums[i-1];
        }
    
    }
    //用前j项 和 - 前i项和 O（1）复杂度得到结果
    int sumRange(int i, int j) {
        return predo[j+1] - predo[i];
    }
};