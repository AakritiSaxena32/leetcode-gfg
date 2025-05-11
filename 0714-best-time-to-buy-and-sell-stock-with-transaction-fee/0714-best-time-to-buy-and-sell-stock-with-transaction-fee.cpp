class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        int curbuy = 0, curnotbuy = 0, aheadbuy=0, aheadnotbuy=0;
        for(int i=n-1; i>=0; i--)
        {
            curnotbuy = max(aheadbuy+prices[i], aheadnotbuy);
            curbuy = max(aheadnotbuy-prices[i]-fee, aheadbuy);
            aheadbuy=curbuy;
            aheadnotbuy=curnotbuy;
        }
        return aheadbuy;
    }
};