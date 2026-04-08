class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0; 
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int target = sum - x;
        if(target == 0) return n;
        int i = 0, j = 0;
        int s = 0;
        int maxlen = 0;
        while(j < n)
        {
            s += nums[j];
            while(i < n && s > target)
            {
                s -= nums[i];
                i++;
            }
            if(s == target)  maxlen = max(maxlen, j-i+1);
            j++;
        }
        if(!maxlen) return -1;
        return n - maxlen;
    }
};