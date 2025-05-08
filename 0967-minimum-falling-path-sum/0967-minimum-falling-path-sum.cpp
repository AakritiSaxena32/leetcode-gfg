class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int i=0; i<m; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];

                int diagonal_right = 0;
                if(j < m-1) diagonal_right = matrix[i][j] + dp[i-1][j+1];
                else diagonal_right+=1e9;

                int diagonal_left = 0;
                if(j>0) diagonal_left = matrix[i][j] + dp[i-1][j-1];
                else diagonal_left += 1e9;

                dp[i][j] = min(up, min(diagonal_right, diagonal_left));
            }
        }
        int mini = dp[n-1][0];
        for(int i=1; i<m; i++)
        {
            mini = min(mini, dp[n-1][i]);
        }
        return mini;
    }
};