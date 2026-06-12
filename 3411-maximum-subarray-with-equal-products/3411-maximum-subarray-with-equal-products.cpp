class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            long long prod = nums[i], l = nums[i], g = nums[i];
            for(int j = i + 1; j < n; j++)
            {
                prod *= nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);
                if(prod == l*g)
                {
                    maxlen = max(j-i+1, maxlen);
                }
                else
                {
                    break;
                }
            }
        }
        return maxlen;
    }
};