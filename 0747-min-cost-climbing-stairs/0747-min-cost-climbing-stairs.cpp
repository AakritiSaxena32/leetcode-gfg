class Solution {
    // int f(int i, vector<int> &dp, vector<int>&cost)
    // {
    //     if(i==0 || i==1) return cost[i];
    //     if(i<0) return 0;
    //     if(dp[i] !=-1) return dp[i];
    //     return dp[i] = min(cost[i]+f(i-1,dp, cost), cost[i]+f(i-2, dp, cost));
    // }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n, -1);
        // int cst = min(f(n-1, dp, cost), f(n-2, dp, cost));
        // return cst;

        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};