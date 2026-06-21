class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long first = (long long)INT_MIN-1;
        long long sec = (long long)INT_MIN-1;
        long long third = (long long)INT_MIN-1;
        for(int i = 0; i < n; i++)
        {
            if(first < nums[i])
            {
                third = sec;
                sec = first;
                first = nums[i];
            }
            else if(nums[i] > sec && nums[i] < first)
            {
                third = sec;
                sec = nums[i];
            }
            else if(nums[i] > third && nums[i] < sec)
            {
                third = nums[i];
            }
        }
        if(n < 3 || third == (long long)INT_MIN-1) return first;
        return third;
    }
};