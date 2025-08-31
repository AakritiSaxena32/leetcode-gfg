class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        //APPROACH1__________________________________
        // int b = 0, m = n-2;
        // sort(piles.begin(), piles.end());
        // int maxCoins = 0;
        // while(m>b)
        // {
        //     maxCoins += piles[m];
        //     m -= 2;
        //     b += 1;
        // }
        // return maxCoins;

        //APPROACH2____________________________________________
        sort(piles.begin(), piles.end());
        int coins = 0;
        for(int i = n/3; i<n; i += 2)
        {
            coins += piles[i];
        }
        return coins;
    }
};