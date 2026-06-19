class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int highestAltitude = 0;
        int prev = 0;
        for(int i = 0; i < n; i++)
        {
            int netgain = prev + gain[i];
            highestAltitude = max(highestAltitude, netgain);
            prev = netgain;
        }
        return highestAltitude;
    }
};