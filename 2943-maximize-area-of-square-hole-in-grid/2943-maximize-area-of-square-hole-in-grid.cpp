class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxConsHbars = 1;
        int maxConsVbars = 1;
        int currConsBars = 1;
        for(int i = 1; i < hBars.size(); i++)
        {
            if(hBars[i] - hBars[i-1] == 1)
                currConsBars++;
            else
                currConsBars = 1;
            maxConsHbars = max(currConsBars, maxConsHbars);
        }
        currConsBars = 1;
        for(int i = 1; i < vBars.size(); i++)
        {
            if(vBars[i] - vBars[i-1] == 1)
                currConsBars++;
            else
                currConsBars = 1;
            maxConsVbars = max(maxConsVbars, currConsBars);
        }
        int side = min(maxConsHbars, maxConsVbars) + 1;
        return side*side;
    }
};