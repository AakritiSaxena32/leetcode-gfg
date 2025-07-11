class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        int m = startTime.size();
        vector<int> freeArray;
        freeArray.push_back(startTime[0]);
        for(int i = 1; i<m; i++)
        {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }
        freeArray.push_back(eventTime - endTime[m-1]);

        int n = freeArray.size();
        vector<int>maxLeftshift(n, 0);
        vector<int>maxRightshift(n, 0);

        for(int i=n-2; i>=0; i--)
        {
            maxRightshift[i] = max(maxRightshift[i+1], freeArray[i+1]);
        }
        for(int i = 1; i<n; i++)
        {
            maxLeftshift[i] = max(maxLeftshift[i-1], freeArray[i-1]);
        }

        int result = 0;
        for(int i=1; i<n; i++)
        {
            int currEventTime = endTime[i-1] - startTime[i-1];

            if(currEventTime <= max(maxLeftshift[i-1], maxRightshift[i]))
            {
                result = max(result, currEventTime+freeArray[i-1]+freeArray[i]); 
            }
            result = max(result, freeArray[i-1]+freeArray[i]);
        }
        return result;
    }
};