class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        long long rem  = 0;
        vector<bool> ans;
        for(int i = 0; i < n; i++)
        {
            rem = ((rem * 2)+nums[i])%5;
            if(rem == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};