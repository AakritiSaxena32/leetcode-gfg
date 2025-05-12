class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i-1; j>=-1; j--)
            {
                len = 0 + dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j])
                    len = max(len, 1 + dp[i+1][i+1]);
                dp[i][j+1] = len;
            }
        }
        return dp[0][0];
    }
};