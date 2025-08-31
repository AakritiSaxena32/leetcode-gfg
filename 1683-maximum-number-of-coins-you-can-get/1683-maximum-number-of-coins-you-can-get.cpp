class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int b = 0, a = n-1, m = n-2;
        sort(piles.begin(), piles.end());
        int maxCoins = 0;
        while(m>b)
        {
            maxCoins += piles[m];
            m -= 2;
            a -= 2;
            b += 1;
        }
        return maxCoins;
    }
};