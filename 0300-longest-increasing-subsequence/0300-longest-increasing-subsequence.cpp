class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // int len = 0;
        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        // for(int i=n-1; i>=0; i--)
        // {
        //     for(int j=i-1; j>=-1; j--)
        //     {
        //         len = 0 + dp[i+1][j+1];
        //         if(j==-1 || nums[i]>nums[j])
        //             len = max(len, 1 + dp[i+1][i+1]);
        //         dp[i][j+1] = len;
        //     }
        // }
        // return dp[0][0];


        //SPACE OBTIMIZATION
        // int n = nums.size();
        // vector<int> next(n+1, 0), cur(n+1, 0);
        // int len=0;
        // for(int ind=n-1; ind>=0; ind--)
        // {
        //     for(int prev=ind-1; prev>=-1; prev--)
        //     {
        //         len = 0 + next[prev+1];
        //         if(prev==-1 || nums[ind]>nums[prev])
        //             len = max(len, 1+ next[ind+1]);
        //         cur[prev+1] = len;
        //     }
        //     next = cur;
        // }
        // return next[0];


        //*************************************METHOD 2****************************************
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int maxi = 1;
        for(int ind=0; ind<n; ind++)
        {
            for(int prev=0; prev<ind; prev++)
            {
                if(nums[ind]>nums[prev])
                {
                    dp[ind] = max(dp[ind], 1+dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};