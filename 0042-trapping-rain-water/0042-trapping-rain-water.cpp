class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0] = height[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = max(prefix[i-1], height[i]);
        }
        suffix[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--)
        {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        int total = 0;
        for(int i=0; i<n; i++)
        {
            int leftMost = prefix[i];
            int rightMost = suffix[i];
            if(height[i] < leftMost && height[i] < rightMost)
            {
                total += min(leftMost, rightMost) - height[i];
            }
        }
        return total;
    }
};