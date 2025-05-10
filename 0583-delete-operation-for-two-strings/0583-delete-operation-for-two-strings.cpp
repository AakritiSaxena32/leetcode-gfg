class Solution {
    int lcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int len = lcs(word1, word2);
        int n = word1.size(), m = word2.size(); 
        int del1 = n - len;
        int del2 = m - len;
        return del1+del2;
     }
};