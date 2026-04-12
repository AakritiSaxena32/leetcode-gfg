class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int e = 0, o = 0;
        for(int pos: position)
        {
            if(pos % 2 == 0) e++;
            else o++; 
        }
        return min(e, o);
    }
};