class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(k, 0);
        freq[0] = 1;
        int prefSum = 0;
        int subArrCnt = 0;
        for(int num: nums)
        {
            prefSum += num;
            int rem = ((prefSum % k) + k) % k; //to handle -ve rem
            subArrCnt += freq[rem];
            freq[rem]++;
        }
        return subArrCnt;
    }
};