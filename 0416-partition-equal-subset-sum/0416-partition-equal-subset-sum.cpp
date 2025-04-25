class Solution {
    bool subsetSum(vector<int>&nums, int sum)
    {
        int n = nums.size();
        vector<vector<bool>>t (n+1, vector<bool>(sum+1));
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(i==0)
                {
                    t[i][j] = false;
                }
                if(j==0)
                {
                    t[i][j] = true;
                }
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(j>=nums[i-1])
                {
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int Sum = 0; 
        for(int i=0; i<nums.size(); i++)
        {
            Sum+=nums[i];
        }
        if(Sum % 2!=0)
            return false;
        else
            return subsetSum(nums, Sum/2);
    }
};