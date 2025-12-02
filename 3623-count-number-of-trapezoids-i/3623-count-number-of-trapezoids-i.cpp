class Solution {
public:
    int M = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) 
    {
        int n = points.size();
        unordered_map<int, int> mpp;
        for(auto &point: points)
        {
            mpp[point[1]]++;
        }    
        long long result = 0;
        long long previousHorizontalLines = 0;
        for(auto& it: mpp)
        {
            long long count = it.second;
            long long HorizontalLines = count * (count-1)/2;
            result += HorizontalLines * previousHorizontalLines;
            previousHorizontalLines += HorizontalLines;
        }
        return result % M;
    }
};