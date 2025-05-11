class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        // for(int ind=n-1; ind>=0; ind--)
        // {
        //     for(int buy=0; buy<2; buy++)
        //     {
        //         for(int cap=1; cap<3; cap++)
        //         {
        //             if(buy == 1)
        //             { 
        //                 dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap] , dp[ind+1][1][cap]);
        //             }
        //             else
        //             {
        //                 dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];

        //*********************************METHOD2*************************************************
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        for(int i = n-1; i>=0; i--)
        {
            for(int j = 3; j>=0; j--)
            {
                if(j%2==0)
                    dp[i][j] = max(-prices[i]+dp[i+1][j+1], dp[i+1][j]);
                else
                    dp[i][j] = max(prices[i]+dp[i+1][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};