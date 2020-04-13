有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i <stones.size(); ++i)
        {
            pq.push(stones[i]);
        }
        
        int first =0;
        int second =0;
        while(pq.size() > 1)
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();

            if(first == second)
                continue;
            if(first > second)
                pq.push(first-second);
            else 
                pq.push(second-first);
        }
        if(pq.size() == 1)
            return pq.top();
        return 0;
    }
};