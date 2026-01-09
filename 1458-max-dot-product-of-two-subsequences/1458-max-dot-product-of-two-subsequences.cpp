// class Solution {
// public:
//         const int INF = 10e7;
//         int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -INF));
//         for (int i=1; i<=n; i++) {
//             for (int j=1; j<=m; j++) {
//                 dp[i][j] = max({
//                                 nums1[i-1]*nums2[j-1],
//                                 dp[i-1][j-1] + nums1[i-1]*nums2[j-1],
//                                 dp[i-1][j],
//                                 dp[i][j-1]
//                                });
//             }
//         }
//         return dp[n][m];
//     }
// };


// class Solution {
//     vector<vector<int>> t;
//     int m, n;
//     int solve(vector<int>& nums1, vector<int>& nums2, int i , int j)
//     {
//         if(i == n || j == m) return -1e9;
//         if(t[i][j] != -1e9) return t[i][j];
//         int val = nums1[i] * nums2[j];
//         int take_ij = val + solve(nums1, nums2, i+1, j+1);
//         int take_i = solve(nums1, nums2, i, j+1);
//         int take_j = solve(nums1, nums2, i+1, j);
//         return t[i][j] = max(val, max(take_ij ,max(take_i, take_j)));
//     }
// public:
//         int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         n = nums1.size();
//         m = nums2.size();
//         t.resize(n, vector<int>(m, -1e9));
//         int result = solve(nums1, nums2, 0, 0);
//         return result;
//     }
// };

class Solution {
public:
        int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1e9));
        for(int i = n; i >= 0; i--)
        {
            for(int j = m; j >= 0; j--)
            {
                if(i == n || j == m) 
                {
                    dp[i][j] = -1e9;
                    continue;
                }
                int val = nums1[i] * nums2[j];
                int take_ij = val + max(0, dp[i+1][j+1]);
                int take_i = dp[i][j+1];
                int take_j = dp[i+1][j];
                dp[i][j] = max(val, max(take_ij, max(take_i, take_j)));
            }
        }
        return dp[0][0];
    }
};