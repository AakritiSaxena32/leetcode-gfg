class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int j = 0; j<n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int down = dp[i+1][j]+triangle[i][j];
                int diagonal = dp[i+1][j+1]+triangle[i][j];
                dp[i][j] = min(down, diagonal); 
            }
        }
        return dp[0][0];
    }
};