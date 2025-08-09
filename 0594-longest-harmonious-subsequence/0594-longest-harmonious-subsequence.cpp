class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size(), result = 0;
        unordered_map<int, int> mpp;
        for(auto & num: nums)
        {
            mpp[num]++;
        }
        for(auto &num: nums)
        {
            int minNum = num;
            int maxNum = num+1;
            if(mpp.find(maxNum) != mpp.end())
            {
                result = max(result, mpp[minNum] + mpp[maxNum]);
            }
        }
        return result;
    }
};