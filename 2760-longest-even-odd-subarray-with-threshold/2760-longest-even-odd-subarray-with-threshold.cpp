class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int i = 0, j = 0;
        int flag = 0;
        int maxlen = 0; 
        while(j < n)
        {
            if(flag == 0)
            {
                if(nums[j] % 2 == 0 && nums[j] <= threshold)
                {
                    i = j;
                    maxlen = max(maxlen, j-i+1);
                    flag = 1;
                }
            }
            else if(flag == 1)
            {
                if((nums[j-1]%2 != nums[j]%2) && nums[j] <= threshold)
                {
                    maxlen = max(maxlen, j-i+1);
                }
                else
                {
                    flag = 0;
                    j--;
                }
            }
            j++;
        }
        return maxlen;
    }
};