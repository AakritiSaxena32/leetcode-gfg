class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int N : nums) {
            if (N % 2 == 0) { // even
                ans.push_back(-1);
                continue;
            }
            int found = -1;
            for (int x = 1; x < N; x++) {
                if ((x | (x + 1)) == N) {
                    found = x;
                    break;
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};