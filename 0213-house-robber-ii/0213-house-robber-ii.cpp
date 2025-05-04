class Solution {
    int maxAdjSum(vector<int>& nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        int n = nums.size(); 
        for(int i=1; i<n; i++)
        {
            int take = nums[i];
            if(i>1) take+= prev2;
            int nontake = prev;
            int curi = max(take, nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(maxAdjSum(temp1), maxAdjSum(temp2));
    }
};