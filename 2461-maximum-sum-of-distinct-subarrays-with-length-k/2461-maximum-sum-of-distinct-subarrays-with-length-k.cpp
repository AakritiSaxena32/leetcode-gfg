class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0, n = nums.size();
        long long maxSum = 0;
        long long sum = 0;
        while(j < n)
        {
            if(mpp.find(nums[j]) == mpp.end())
            {
                mpp[nums[j]] = j;
                sum += nums[j];
            }
            else
            {
                if(i<j)
                {
                    sum -= nums[i];
                    mpp.erase(nums[i]);
                    i++;
                }
                continue;
            }
            if(j-i+1 == k)
            {
                maxSum = max(maxSum, sum);
                sum -= nums[i];
                mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxSum;
    }
};