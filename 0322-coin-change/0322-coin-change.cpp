class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int m = amount;
        vector<vector<int>> dp (n+1, vector<int>(m+1,-1));

        for(int j=0; j<=m; j++)
        {
            dp[0][j] = INT_MAX-1;
        }

        for(int i=1; i<=n; i++)
        {
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(j%coins[0]==0)
                {
                    dp[i][j] = j/coins[0];
                }
                else
                {
                    dp[i][j] = INT_MAX-1;
                }
            }
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(coins[i-1]<=j) dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][m] >= INT_MAX-1)?-1: dp[n][m];
    }
};