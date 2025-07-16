class Solution {
public:
    int maximumLength(vector<int>& nums)
    {
        int n = nums.size(), i = 1, oddcnt = 0, evencnt = 0, altcnt = 1;
        for(i=0; i<n; i++)
        {
            if(nums[i]%2 == 0) evencnt++;
            else oddcnt++;
        }
        int parity = nums[0]%2;
        i=1;
        while(i<n)
        {
            int currParity = nums[i]%2;
            if(currParity != parity)
            {
                parity = currParity;
                altcnt++;
            }
            i++;
        }
        return max(altcnt, max(oddcnt, evencnt));
    }
};