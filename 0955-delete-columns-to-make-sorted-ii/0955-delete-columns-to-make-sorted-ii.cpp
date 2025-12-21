class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletion = 0;
        vector<bool> isSorted(rows, false);
        for(int col = 0; col < cols; col++)
        {
            bool deleted = false;
            for(int row = 0; row < rows-1; row++)
            {
                if(!isSorted[row] && strs[row][col] > strs[row+1][col])
                {
                    deletion++;
                    deleted = true;
                    break; 
                }
            }
            if(deleted)
            {
                continue;
            }
            for(int i = 0; i < rows-1; i++)
            {
                isSorted[i] = isSorted[i] | (strs[i][col] < strs[i+1][col]);
            }
        }
        return deletion;
    }
};