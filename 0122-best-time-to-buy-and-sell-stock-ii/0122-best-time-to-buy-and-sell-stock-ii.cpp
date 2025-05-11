class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> prev(2,0), cur(2,0);
        int profit=0;
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<2; buy++)
            {
                if(buy)
                {
                    profit = max(-prices[ind]+prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[ind]+prev[1], prev[0]);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }
};