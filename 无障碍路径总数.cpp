class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        //注意 力抠测试用例多 ，尽量采用 long long int 
        if(obstacleGrid.empty()) return 0;
        int  row = obstacleGrid.size();
        int  col = obstacleGrid[0].size();
        //全初始化为 0   0代表此路不通
        vector<vector <long long int>> s(row,                                   vector<long long int>(col, 0));
        //处理上边界
        for(int i=0; i < row; ++i)
        {
            if(obstacleGrid[i][0] == 0)
                s[i][0] = 1;//修改通路
            else 
                break;//此路不通
        }
        //处理左边界
        for(int i= 0; i < col; ++i)
        {
            if(obstacleGrid[0][i] == 0)
                s[0][i] =1 ;//修改通路
            else 
                break;  //此路不通
        }

        for(int i=1; i<row; ++i)
        {
            for(int j=1; j<col; ++j)
            {
                if(obstacleGrid[i][j] == 0)
                    s[i][j] = s[i-1][j] + s[i][j-1];
            }
        }
     return  s[row-1][col-1];
    }
};