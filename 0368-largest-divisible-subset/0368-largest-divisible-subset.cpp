class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1), hash(n,1);
        for(int i=0; i<n; i++)
        {
            hash[i] = i;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
        } 

        int ans = -1, lastindex=-1;

        for(int i=0; i<n; i++)
        {
            if(ans<dp[i])
            {
                ans = dp[i];
                lastindex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};