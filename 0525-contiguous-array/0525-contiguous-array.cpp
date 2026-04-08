class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> seen;
        int maxlen = 0;
        seen[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (nums[i] == 0)? -1 : 1;
            if(seen.count(sum)) maxlen = max(maxlen, i - seen[sum]);
            else seen[sum] = i;
        }
        return maxlen;
    }
};