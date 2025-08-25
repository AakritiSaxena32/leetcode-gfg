class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size();
        int maxUnsatCust = 0, currUnsatCust = 0;
        for(int i = 0; i<minutes; i++)
        {
            currUnsatCust += customers[i]*grumpy[i];
        }
        maxUnsatCust = currUnsatCust;
        int i = 0, j = minutes;
        while(j<n)
        {
            currUnsatCust += customers[j] * grumpy[j];
            currUnsatCust -= customers[i] * grumpy[i];
            maxUnsatCust = max(currUnsatCust, maxUnsatCust);
            j++;
            i++;
        }
        int totalSat = maxUnsatCust;
        for(i = 0; i<n; i++)
        {
            totalSat += customers[i]*(1-grumpy[i]);
        }
        return totalSat;
    }
};