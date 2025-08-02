class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size(), i=0, j=0, zeroes=0, maxlen=0, len=0;
        while(j<n)
        {
            if(nums[j] == 0) zeroes++;
            if(zeroes > k)
            {
                if(nums[i] == 0) zeroes--;
                i++;
            } 
            if(zeroes <= k)
            {
                len = j-i+1;
                maxlen = max(maxlen, len);
            }
            j++;
        }
        return maxlen;
    }
};