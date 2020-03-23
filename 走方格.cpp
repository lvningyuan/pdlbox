class Solution {
public:
    int uniquePaths(int m, int n) {
        //C(n+m-2) (n-1)
        //Cn（m） = Cn-1（m） + Cn-1（m-1）

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



    }
};