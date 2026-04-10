class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        // int n = prices.size();
        // int curbuy=0, curnotbuy=0, prevbuy=0, prevnotbuy=0;
        // for(int ind=n-1; ind>=0; ind--)
        // {
        //     curnotbuy = max(prices[ind]+prevbuy, prevnotbuy);
        //     curbuy = max(-prices[ind]+prevnotbuy, prevbuy);
        //     prevnotbuy = curnotbuy;
        //     prevbuy = curbuy;
        // }
        // return prevbuy;

        int n = prices.size();
        int profit = 0;
        for(int i = 1; i < n; i++)
        {
            if(prices[i] > prices[i-1])
            {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};