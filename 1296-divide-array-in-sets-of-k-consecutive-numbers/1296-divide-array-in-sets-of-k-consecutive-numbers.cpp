class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        int freq;
        for(int &num : nums) mpp[num]++;
        for(auto& it: mpp)
        {
            if(it.second > 0)
            {
                freq = it.second;
                for(int i = 0; i < k; i++)
                {
                    if(mpp[it.first + i] < freq) return false;
                    else mpp[it.first + i] -= freq;
                }
            }
        }
        return true;
    }
};