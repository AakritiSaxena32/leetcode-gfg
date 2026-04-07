class NumMatrix {
public:
    vector<vector<int>> pref;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        pref.resize(m , vector<int>(n,0));
        for(int i = 0; i < m; i++)
        {
            pref[i][0] = matrix[i][0];
            for(int j = 1; j < n; j++)
            {
                pref[i][j] = pref[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
        {
            sum += (pref[i][col2] - ((col1 - 1 >= 0)? pref[i][col1 - 1]: 0));
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */