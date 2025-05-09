class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long>> dp(n, vector<unsigned long>(amount+1, 0));
        for(int j=0; j<=amount; j++)
        {
            dp[0][j] = (j%coins[0]==0);
        }
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                unsigned long nottake = dp[i-1][j];
                unsigned long take = 0;
                if(coins[i]<=j) take = dp[i][j-coins[i]];
                dp[i][j] = nottake + take;
            }
        }
        return dp[n-1][amount];
    }
};