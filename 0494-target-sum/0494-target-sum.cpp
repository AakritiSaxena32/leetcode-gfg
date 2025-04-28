class Solution {
    int subsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1,0));
        for(int i=0; i<=n; i++) t[i][0] = 1;
       
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1] <= j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]]+t[i-1][j];
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0; 
        for(int i=0; i<n; i++) sum+=nums[i];
        if((sum+target)%2!=0 || sum<abs(target))
        {
            return 0;
        }
        int s1 = (target+sum)/2;
        int countzeroes = count(nums.begin(), nums.end(), 0);
        vector<int> filtered;
        for(int num: nums)
        {
            if(num!=0) filtered.push_back(num);
        }
        return subsetSum(filtered, s1)*(1<<countzeroes);
    }
};