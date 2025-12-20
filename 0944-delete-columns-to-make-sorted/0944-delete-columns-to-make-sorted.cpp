class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int ans = 0;
        int i = 0, j = 0;
        while(j < col)
        {
            i = 0;
            bool found = false;
            while(i < row - 1)
            {
                if(strs[i][j] > strs[i+1][j])
                {
                    found = true;
                }
                i++;
            }
            if(found) ans++;
            j++;
        }
        return ans;
    }
};