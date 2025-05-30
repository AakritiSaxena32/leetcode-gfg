class Solution {
    int f(int i, vector<int> &dp, vector<int>&cost)
    {
        if(i==0 || i==1) return cost[i];
        if(i<0) return 0;
        if(dp[i] !=-1) return dp[i];
        return dp[i] = min(cost[i]+f(i-1,dp, cost), cost[i]+f(i-2, dp, cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int cst = min(f(n-1, dp, cost), f(n-2, dp, cost));
        return cst;
    }
};