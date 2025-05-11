class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int curbuy=0, curnotbuy=0, prevbuy=0, prevnotbuy=0;
        for(int ind=n-1; ind>=0; ind--)
        {
            curnotbuy = max(prices[ind]+prevbuy, prevnotbuy);
            curbuy = max(-prices[ind]+prevnotbuy, prevbuy);
            prevnotbuy = curnotbuy;
            prevbuy = curbuy;
        }
        return prevbuy;
    }
};