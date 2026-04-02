class Solution {
    int dp[501][501][3];
    int solve(int i, int j, int m, int n, vector<vector<int>>&coins, int neu)
    {
        if(i == m-1 && j == n-1)
        {
            if(coins[i][j] < 0 && neu > 0)
            {
                return 0;
            }
            return coins[i][j];
        }
        if(i >= m || j >= n)
        {
            return INT_MIN;
        }
        if(dp[i][j][neu] != INT_MIN) return dp[i][j][neu];
        //Take
        int take = coins[i][j] + max(solve(i+1, j, m, n, coins, neu), solve(i, j+1, m, n, coins, neu));
        //skip
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0)
        {
            int skipD = solve(i+1, j, m, n, coins, neu-1);
            int skipR = solve(i, j+1, m, n, coins, neu-1);
            skip = max(skipD, skipR); 
        }
        return dp[i][j][neu] = max(take, skip);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        for(int i = 0; i < 501; i++)
        {
            for(int j = 0; j < 501; j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(0, 0, m, n, coins, 2);
    }
};