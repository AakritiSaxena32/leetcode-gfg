class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // vector<vector<int>> res(n, vector<int>(n,0));
        // for(auto query: queries)
        // {
        //     int stx = query[0];
        //     int sty = query[1];
        //     int edx = query[2];
        //     int edy = query[3];
        //     for(int x = stx; x <= edx; x++)
        //     {
        //         for(int y = sty; y <= edy; y++)
        //         {
        //             res[x][y] += 1; 
        //         }
        //     }
        // }
        // return res;

        vector<vector<int>> res (n+1, vector<int>(n,0));
        for(auto& q: queries)
        {
            const int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            res[r1][c1]++;
            res[r2+1][c1]--;
            if(c2+1 < n)
            {
                res[r1][c2+1]--;
                res[r2+1][c2+1]++;
            }
        }
        for(int i = 0; i < n; i++)
            {
                for(int j = 1; j < n; j++)
                {
                    res[i][j] += res[i][j-1];
                }
            }
            for(int j = 0; j < n; j++)
            {
                for(int i = 1; i < n; i++)
                {
                    res[i][j] += res[i-1][j];
                }
            }
        res.resize(n);
        return res;
    }
};