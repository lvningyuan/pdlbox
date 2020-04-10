## 题目描述

一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci


![在这里插入图片描述](https://img-blog.csdnimg.cn/20200410083704225.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDAzMDU4MA==,size_16,color_FFFFFF,t_70)



## 思路分析：

很明显本体需要动态权衡，选择一件事情做或者不做，
限制： 做这个，就不能做前一个。
目的： 做最大业务，时间最长的

那么我们用一维数组动态存-------->每件事当前最长时间，每来一项业务：
		1  做：当前业务总时长 =  当前 +  前前业务总和
		2  不做：当前 == 做了 vs  没做    --- 》权衡取其大



```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max (nums[1], nums[0]);

        for(int i =2; i < n; ++i)
        {      
            //能选本个，就不能选取前一个。
            //动态权衡， 取其大
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};
```
上边做法已经双100%

##  理解之后优化：
思路分析：
 			我只要最好的情况，我并不心你选择过程是怎样的，
 			那么也就是说，我不关心中途实时最优方案，
 			换句话说，我计算到 第5个业务了，我只要知道选择业务3， 选择业务4，两种方案时的时长即可正确判断出我当前的选择与否。


那么数组就显得开销大了。

**解决方案：  迭代**
  
  原因： 每次只需要在前两个最好的方案里面选择， 那么两个变量记录即可，无需数组：
	策略： 迭代更新 
		pprev
		prev
		cur  = max（cost【i】 + pprev ， prev）；
		pprev = prev；
		prev = cur；
 		解释： pprev  代表前前最好情况
 					prev    代表 前一次最好情况
 					cur      当前最好情况（做与不做选定）
于是cost不断的向后走。最终得到  cur即可。


```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
 

        int dp0 = nums[0];
        int dp1 = max (nums[1], nums[0]);
        int cur= dp1;
        for(int i =2; i < n; ++i)
        {      
            //能选本个，就不能选取前一个。
            //动态权衡， 取其大
            cur = max(nums[i] + dp0, dp1);
            dp0 = dp1;
            dp1 =cur;
        }
        return cur;
    }
};
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020041009041359.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDAzMDU4MA==,size_16,color_FFFFFF,t_70)

遗憾的是 ，效率好像下降了～～～  ，但空间实打实的节约了。

所以： 我们做OJ题时，能过就行 哈哈哈哈哈 ，不要过度追求极尽，
**物极必反哦～**