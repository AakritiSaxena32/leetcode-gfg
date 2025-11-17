class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int ones = 0;
        int zeroes = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1 && ones == 0) ones = 1;
            else if(nums[i] == 0 && ones == 1) zeroes++;
            else if(nums[i] == 1) 
            {
                if(zeroes < k) return false;
                else zeroes = 0;
            }
        }
        return true;
    }
};