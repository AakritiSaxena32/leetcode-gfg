class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        int time = 0;
        for(int i = 0; i < n-1; i++)
        {
            int dx = abs(points[i][0] - points[i+1][0]);
            int dy = abs(points[i][1] - points[i+1][1]);
            time += (min(dx, dy) + abs(dy - dx));
        }
        return time;
    }
};