class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int lftsum = 0;
        for(int i = 0; i < n; i++)
        {
            int rtsum = total - lftsum - nums[i];
            if(lftsum == rtsum) return i;
            lftsum += nums[i];  
        }
        return -1;
    }
};