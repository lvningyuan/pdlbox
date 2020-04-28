一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int uniquePaths(int m, int n) {
        //C(n+m-2) (n-1)
        //Cn（m） = Cn-1（m） + Cn-1（m-1）


       /* 
        vector<vector <int>> vv;
        vv.resize(m);
        for(int i=0; i < m; ++i )
        {
            vv[i].resize(n);
        }
        for(int i = 0; i<m; ++i)
        {
            vv[i][0] =1;
        }
        for(int j =0; j < n; ++j)
        {
            vv[0][j] =1;
        }

        for(int i=1; i < m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                vv[i][j] = vv[i-1][j] + vv[i][j-1];
            }
        }
        return vv[m-1][n-1];
    */



    //初始化 m行 ，每行都是一个vector ， 即初始化全1 二维数组
    vector<vector<int>> s(m, vector<int>(n, 1));

    for(int i=1; i<m; ++i)
    {
        for(int j=1; j<n; ++j)
        s[i][j] = s[i-1][j] +  s[i][j-1];
    }
    return s[m-1][n-1];
    }
};