class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int l1 = matrix.size();
        if (l1 == 0) return 0;
        int l2 = matrix[0].size();

        vector<vector<int>> dp(l1,vector<int>(l2));
        
        int maxSide =0;
        for(int i =0; i<l1; ++i)
        for(int j =0; j<l2; ++j)
        {
           if(matrix[i][j] =='1')
           {
               if(i==0 || j==0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1; // 受最短边影响
           }
            maxSide = max(maxSide, dp[i][j]);
        }
            return maxSide * maxSide;
    }
};