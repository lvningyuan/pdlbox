

02. 做菜顺序
一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。

一道菜的「喜爱时间」为烹饪这道菜 + 之前每道菜所花费的时间  乘以这道菜的满意程度，也就是 time[i]*satisfaction[i] 。

请你返回做完所有菜 「喜爱时间」总和的最大值为多少。

你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。

 

示例 1：

输入：satisfaction = [-1,-8,0,5,-9]
输出：14
解释：去掉第二道和最后一道菜，最大的喜爱时间系数和为 (-1*1 + 0*2 + 5*3 = 14) 。每道菜都需要花费 1 单位时间完成。
示例 2：

输入：satisfaction = [4,3,2]
输出：20
解释：按照原来顺序相反的时间做菜 (2*1 + 3*2 + 4*3 = 20)
示例 3：

输入：satisfaction = [-1,-4,-5]
输出：0
解释：大家都不喜欢这些菜，所以不做任何菜可以获得最大的喜爱时间系数。



class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        //目标为了拿最大 ，大的越靠前，重复加的越多
        //因此 安 降序排序  
        //方便起见我们不修改比较器了，直接从后向前升序排序也可以，
        sort(satisfaction.rbegin(), satisfaction.rend());
        int ans =0;
        int tmp =0;

        for(int i=0; i < satisfaction.size(); ++i)
        {
            //因为喜欢时间都是1 所以不用✖️了直接➕
            tmp += satisfaction[i];  
            //当前菜的喜欢时间 小于0 了，那么后边的肯定小于0
            if(tmp < 0) 
                break;
                //因为当前菜喜欢时间 = 本道菜 + 之前的菜
            ans += tmp;//选择做，前边的就得多加一次
        }
        return ans;
    }
};