class Solution {
    int f(int i, int j, vector<vector<int>> &dp, string s, string t)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j])
        {
            return dp[i][j] = f(i-1, j-1, dp, s, t) + f(i-1, j, dp, s, t);
        }
        else
        {
            return dp[i][j] = f(i-1, j, dp, s, t);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(n-1, m-1, dp, s, t);
    }
};