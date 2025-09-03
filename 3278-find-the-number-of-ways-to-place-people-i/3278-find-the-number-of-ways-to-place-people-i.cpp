class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int miny = INT_MIN;
            for(int j = i+1; j<n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(y2 <= y1)
                {
                    if(y2 > miny)
                    {
                        cnt++;
                        miny = y2;
                    }
                }
            }
        }
        return cnt;
    }
};