class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m = 1;
        int num = -1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                m++;
                if(m == n/2)
                {
                   num = nums[i]; 
                }
            }
            else m = 1;
        }
        return num;
    }
};