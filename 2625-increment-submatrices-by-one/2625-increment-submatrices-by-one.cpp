class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n,0));
        for(auto query: queries)
        {
            int stx = query[0];
            int sty = query[1];
            int edx = query[2];
            int edy = query[3];
            for(int x = stx; x <= edx; x++)
            {
                for(int y = sty; y <= edy; y++)
                {
                    res[x][y] += 1; 
                }
            }
        }
        return res;
    }
};