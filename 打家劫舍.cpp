
打家劫舍：
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。



分析： 直接下手不好弄， 从小问题入手，
房间为1   打结
房间为2 	 打劫	max(a[1], a[2])
房间为3   打劫    max(a[1] + a[3], a[2])

因为不能打劫相邻的，所以打劫a[n] 必然不能打劫a[n-1]. 
		因此  想打劫a[n], 前提是打劫范围在 前 a[n-2]家，并获取前a[n-2]家中最大值
		因此，问题逐渐缩小规模到n =2 ， n = 1 逐渐求解
		
	打劫。   max(a[n] + max a[n-2], max a[n-1])
因此打劫的状态方程为 ：
	M(n) = max( a[n] + M(a[n-2]), M(a[n-1]));



class Solution {
public:
    int rob(vector<int>& nums) {
       if(nums.size() == 0)
            return 0;
       if(nums.size() == 1)
            return nums[0];

        int len = nums.size();
        int S[len] = {0};
        S[0] = nums[0];
        S[1] = max(nums[0], nums[1]);
        
        for(int i =2; i < len; ++i)
        {
            S[i] = max(nums[i] + S[i-2], S[i-1]);
        }

        return S[len-1];
    }
};