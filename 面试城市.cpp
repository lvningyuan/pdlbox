公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。

返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-city-scheduling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ret =0; 

        //思路：贪心算法，将所有人可选择的差排序
        //差值越大，costs[i][0]j就越大，排序越靠后，我们反选costs[i][1]
        //差值越小排序越靠前，我们选costs[i][0]即可

        //由于是二维数组，那么需要重载比较器，我们直接用lambda表达式就可以代替仿函数
         sort(costs.begin(), costs.end(), [](vector<int>a, vector<int> b){ return a[0] - a[1] < b[0] - b[1];});

         //注意的是排序的结果选前N个costs[i][0]
         //后N的城市选costs[i][1]
         int n = costs.size()>>1;
         for(int i=0; i < n; ++i)
         {
             ret += costs[i][0] + costs[n+i][1];
         }
     return ret;    
    }
};