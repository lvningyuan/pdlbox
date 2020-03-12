给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

提示：

3 <= A.length <= 50000
-10^4 <= A[i] <= 10^4


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


注意数组大小和元素范围 ，所以不会超过 int

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int  n =0;
        for(int i =0; i< A.size(); ++i)
        {
            n+=A[i];
        }
    if(n % 3 != 0)
        return false;
    int tmp = n / 3;
    cout<<tmp<<endl;
    n =0;
    int partCount =0;
        for(auto i :A)
        {
            n +=i;
           if(n == tmp )
           {
               n =0;
               partCount++;
           }
        }
        if(partCount >= 3)
            return true;
        return false;
    }
};