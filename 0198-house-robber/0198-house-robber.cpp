class Solution {
public:
    int rob(vector<int>& nums)
    {
        /*
        int n = nums.size();
        vector<int> dp (n,-1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i>1) take+=dp[i-2];
            int nontake = 0 + dp[i-1];
            dp[i] = max(take, nontake);
        }
        return dp[n-1];
        */
        int prev = nums[0];
        int prev2 = 0;
        int n = nums.size(); 
        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i>1) take += prev2;
            int nontake = prev;
            int curi = max(take, nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};