class Solution {
    int n;
    int dp[100001][3];
public:
    int binarySearch(vector<vector<int>>& events, int endTime)
    {
        int l = 0; 
        int r = n-1;
        int result = n;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(events[mid][0] > endTime)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>&events, int i, int count)
    {
        if(count == 2 || i >= n)
            return 0;
        if(dp[i][count] != -1)
            return dp[i][count];
        int nextEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextEventIndex, count+1);
        int nottake = solve(events, i+1, count);
        return dp[i][count] = max(take, nottake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        memset(dp, -1, sizeof(dp));
        sort(events.begin(), events.end());
        int count = 0; 
        return solve(events, 0, count); 
    }
};