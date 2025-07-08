class Solution {
    private int binarySearch(int [][] events, int currStart)
    {
        int left = 0, right = events.length-1;
        int res = -1;
        while(left<=right)
        {
            int mid = left+(right - left)/2;
            if(events[mid][1] < currStart)
            {
                res = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1; 
            }
        }
        return res;
    }
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        Arrays.sort(events,(a,b)->(a[1]-b[1]));

        int [][] dp = new int[n+1][k+1];

        for(int i=1; i<n+1; i++)
        {
            int[] event = events[i-1];
            int prev = binarySearch(events, event[0]);

            for(int j=1; j<k+1; j++)
            {
                dp[i][j] = Math.max(dp[i-1][j],dp[prev+1][j-1]+event[2]);
            }
        }
        return dp[n][k];
    }
}