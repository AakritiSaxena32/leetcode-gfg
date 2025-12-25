class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long happy = 0;
        for(int i = 0; i < k; i++)
        {
            happy += ((happiness[i] - i) >= 0)? (happiness[i] - i) : 0;
        }
        return happy;
    }
};