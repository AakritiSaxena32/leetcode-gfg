class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return true;
        int direction = 0;
        int i = 1;
        while(i<n)
        {
            if(nums[i] > nums[i-1])
            {
                if(direction == 0) direction = 1;
                else if (direction == -1) return false;
            }
            else if(nums[i] < nums[i-1])
            {
                if(direction == 0) direction = -1;
                else if(direction == 1) return false;
            }
            i++;
        }
        return true;
    }
};