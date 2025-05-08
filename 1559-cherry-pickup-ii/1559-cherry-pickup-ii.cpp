class Solution {
    int f(int i, int j1, int j2, int c, int r, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp)
    {
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
        if(i == r-1)
        {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int dj1=-1 ; dj1<=1; dj1++)
        {
            for(int dj2=-1; dj2<=1; dj2++)
            {
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1, j1+dj1, j2+dj2, c, r, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(m, vector<int>(m, -1)));
        int max_cherry = f(0, 0, m-1, m, n, grid, dp);
        return max_cherry;
    }
};