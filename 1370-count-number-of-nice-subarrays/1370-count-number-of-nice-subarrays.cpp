class Solution {
    int atmost(vector<int>& nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), res = 0, cnt = 0;
        while(r<n)
        {
            cnt += (nums[r]%2 != 0)? 1: 0;
            while(cnt > k && l<n)
            {
                cnt -= (nums[l]%2 != 0)? 1: 0;
                l++;
            }
            res = res + (r-l+1);
            r++;
        } 
        return res;
    }
    public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};