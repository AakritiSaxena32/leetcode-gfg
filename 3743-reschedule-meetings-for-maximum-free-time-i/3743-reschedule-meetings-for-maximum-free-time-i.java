class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) 
    {
        int n = startTime.length;

        List<Integer>freeArray = new ArrayList<>();
        freeArray.add(startTime[0]);
        for(int i=1; i<n; i++)
        {
            freeArray.add(startTime[i] - endTime[i-1]);
        }
        freeArray.add(eventTime - endTime[n-1]);

        int i = 0, j = 0;
        int currSum = 0, maxSum = Integer.MIN_VALUE;
        while(j < freeArray.size())
        {
            currSum += freeArray.get(j);
            if(j-i+1 > k+1 && i<n)
            {
                currSum -= freeArray.get(i);
                i++;
            } 
            maxSum = Math.max(maxSum, currSum);
            j++;
        }
        return maxSum;
    }
}