class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        int maxSum = 0;
        vector<pair<int, int>>plyrs(n);
        for(int i = 0; i<n; i++)
        {
            plyrs[i] = {ages[i], scores[i]};
        }
        sort(plyrs.begin(), plyrs.end());
        vector<int> dp(n);
        for(int i = 0; i < n ; i++)
        {
            dp[i] = plyrs[i].second;
            for(int j = 0; j < i; j++)
            {
                if(plyrs[j].second <= plyrs[i].second)
                {
                    dp[i] = max(dp[i], plyrs[i].second + dp[j]);
                }
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};