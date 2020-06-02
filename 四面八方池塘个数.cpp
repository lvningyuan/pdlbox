力扣：  1139 ：最大的以 1 为边界的正方形



DP思想 ：  开辟 两个二维数组 ：  保存 左边 、  上边。  
  最坏情况 O（logN^3）
  但是一旦算出来一个值 ，一定结束

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int l1 = grid.size();
        if(l1 == 0) return 0;
        int l2 = grid[0].size();

       vector<vector<int>> top = grid;
       vector<vector<int>> left = grid;

       for(int i =0; i<l1; ++i)
       for(int j =0; j<l2; ++j)
       if(grid[i][j])  //这里不能写 i!=0   j !=0  因为还有i=0 j的其他情况 
        {
            top[i][j] = i>0 ? top[i-1][j]+1 :1;
            left[i][j]= j>0 ? left[i][j-1]+1 :1;
        }

        for(int a =min(l1,l2); a>0; --a)//边长
        for(int i=l1-1; i-a+1>=0; --i)//不能越界 
        for(int j=l2-1; j-a+1>=0; --j)//不能越界
        if(left[i][j]>=a && left[i-a+1][j] >=a && 
                        top[i][j]>=a && top[i][j-a+1] >=a)
        return  a*a;
        return  0;
    }
};