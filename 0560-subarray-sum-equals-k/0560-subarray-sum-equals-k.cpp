class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefix=0, cnt=0, remove;
        for(int i=0; i<nums.size(); i++)
        {
            prefix += nums[i];
            remove = prefix - k;
            cnt += mpp[remove];
            mpp[prefix] += 1;  
        }    
        return cnt;
    }
};