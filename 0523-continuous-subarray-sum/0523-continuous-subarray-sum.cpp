class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long long prefSum = 0;
        for(int i = 0; i < n; i++)
        {
            prefSum += nums[i];
            long long rem = ((prefSum % k) + k) % k;
            if(mpp.count(rem))
            {
                if(i - mpp[rem] > 1)
                {
                    return true;
                }
            }
            else
            {
                mpp[rem] = i;
            }
        }
        return false;
    }
};