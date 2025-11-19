class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n)
        {
            if(nums[i] == original)
            {
                original = original * 2;
            }
            i++;
        }
        return original;
    }
};