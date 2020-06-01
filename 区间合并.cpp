
## leetcode 56 区间合并


很迷人的写出了个递归代码 ，， 汗 。我再试着写成循环吧
```cpp
class Solution {
private:
    vector<vector<int>> ret;
private:
    void grid(vector<vector<int>>& intervals, int index){
        if(index == intervals.size()) {
            ret.push_back(intervals[index-1]);
            return ;
        }

        if(intervals[index][0] <= intervals[index-1][1])
        {
            intervals[index][0] = intervals[index-1][0];
            intervals[index][1] = max(intervals[index][1], intervals[index-1][1]);
        }
        else
            ret.push_back(intervals[index-1]);
        grid(intervals, index+1);
   }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ret .clear();
        int len = intervals.size();
        if (len <= 1) return intervals;

        //回溯： 数组头排序
        sort(intervals.begin(), intervals.end(),[&](vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        grid(intervals, 1);
        return ret;
    }
};
```






**//   O(n logN )  //快排慢了点 主要处理还是很快的** 

```cpp
class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ret .clear();
        int len = intervals.size();
        if (len <= 1) return intervals;

        //回溯： 数组头排序
        sort(intervals.begin(), intervals.end(),[&](vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int index =1;
        while(index <= len){
        if(index == len ){
            ret.push_back(intervals[index-1]);
            break;
        }
        if(intervals[index][0] <= intervals[index-1][1]){  
            intervals[index][0] = intervals[index-1][0];
            intervals[index][1] = max(intervals[index][1], intervals[index-1][1]);
        }
        else
            ret.push_back(intervals[index-1]);
        ++index;
        }
        return ret;
    }
};
```
