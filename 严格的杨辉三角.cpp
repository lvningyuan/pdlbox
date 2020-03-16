严格要求不能有空格的杨辉三角


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vv;
        if(numRows == 0)
            return vv;

        vv.resize(numRows);
        for(int i = 0; i<numRows; ++i)
        {
            vv[i].resize(i+1);
            vv[i][0] = 1;
            vv[i][i] = 1;
        }

        for(int i =2; i<numRows; ++i)
        {
            for(int j=1; j < i ; ++j)
            {
                vv[i][j] = vv[i-1][j] +vv[i-1][j-1];
            }
        }
        return vv;
    }
};