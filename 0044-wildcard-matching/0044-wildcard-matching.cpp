class Solution {
    // bool f(int i, int j, string s, string p, vector<vector<int>> &dp)
    // {
    //     if(i==0 && j==0) return true;
    //     if(i==0 && j>0) return false;
    //     if(i>0 && j==0)
    //     {
    //         for(int ii=1; ii<=i; ii++)
    //         {
    //             if(p[ii-1] != '*')
    //             {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i-1] == p[j-1] || p[j-1] != '?')
    //     {
    //         return dp[i][j] = f(i-1, j-1, s, p, dp);
    //     }
    //     if(p[i-1] == '*')
    //     {
    //         return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
    //     }
    //     return false;
    // }
public:
    bool isMatch(string s, string p) {
        // int n = s.size();
        // int m = p.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return f(n-1, m-1, s, p, dp);

        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;

        for(int j=1; j<=m; j++) 
        {
            dp[0][j] = false;
        }

        for(int j=1; j<=m; j++)
        {
            if(p[j-1]=='*')
            {
               dp[0][j] = dp[0][j-1];
            }
            else
            {
                break;
            }
        }
        

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};