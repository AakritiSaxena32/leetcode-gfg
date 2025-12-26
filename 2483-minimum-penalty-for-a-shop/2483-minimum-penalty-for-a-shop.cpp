class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int maxPenalty = 0;
        int bestTime = -1;
        int prefix = 0;
        for(int i = 0; i < n; i++)
        {
            prefix += (customers[i] == 'Y')? 1: -1;
            if(maxPenalty < prefix)
            {
                bestTime = i;
                maxPenalty = prefix;
            }
        }
        return bestTime + 1;
    }
};