class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     /*
        vector<int> dp(triangle.size()+1,0);//初始化为0
        //为什么需要多一个数组空间，因为每次取两个路径长度比较并提取其中最小的。

       //自底向上
        for(int i=triangle.size()-1; i>=0; i--)
        {
            for(int j=0; j<triangle[i].size(); j++) 
            {
                //每求完一层，新一层数据一旦出来就可以覆盖掉
                //原有数据了，（原数据用不上了）
         dp[j] = min(dp[j],dp[j+1]) +  triangle[i][j];
            }
        }
        return dp[0];
    */




/*
    vector<vector <int> > s(triangle);

    s[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); ++i)
    {
        s[i][0] = s[i-1][0] + triangle[i][0];
        s[i][i] = s[i-1][i-1] + triangle[i][i];
    }

    //注意这里的范围  
    for(int i=2; i < triangle.size(); ++i)
    {
        //注意这里的范围 ：列 不能到最后一列
        for(int j=1; j < i; ++j)
        {
            s[i][j] = min(s[i-1][j-1], s[i-1][j]) + triangle[i][j]; 
        }
    }

    int ret =s[triangle.size()-1][0];
    for(int i = 0; i < triangle.size(); ++i)
    {
        if(ret > s[triangle.size()-1][i])
            ret = s[triangle.size()-1][i];
    }
    return ret;
    */

    
    //自底向上：最快做法， 若想节省空间，一维数组也可以 
    /*
    vector<vector <int> > s(triangle);

    for(int i =triangle.size()-2; i >= 0; --i)
    {
        for(int j=0; j <= i; ++j)
        {
            s[i][j] = min(s[i+1][j], s[i+1][j+1])+triangle[i][j];
        }
    }
    return s[0][0];
    */



    //自底向上一维数组;   
    vector<int> s(triangle[triangle.size()-1]);

    for(int i=triangle.size()-2; i >=0; --i)
    {
        for(int j=0; j<=i; ++j)
        {
            s[j] = triangle[i][j] + min(s[j+1],s[j]); 
        }
    }
    return s[0];
   }
};