class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        // int n = prices.size();
        // vector<int> after(2*k+1, 0), curr(2*k+1, 0);
        // for(int ind = n-1; ind>=0; ind--)
        // {
        //     for(int tranNo = 2*k-1; tranNo>=0; tranNo--)
        //     {
        //         if(tranNo%2 == 0)
        //             curr[tranNo] = max(-prices[ind]+after[tranNo+1], after[tranNo]);
        //         else
        //             curr[tranNo] = max(prices[ind]+after[tranNo+1], after[tranNo]);
        //     }
        //     after = curr;
        // }
        // return after[0]; 

        int n = prices.size();
        if(n <= 1 || k == 0) return 0;
        vector<int>buy(k,INT_MIN);
        vector<int>sell(k,0);
        for(int p : prices)
        {
            for(int j = 0; j < k; j++)
            {
                if(j == 0) buy[0] = max(buy[0], -p);
                else buy[j] = max(buy[j], sell[j-1]-p);
                sell[j] = max(sell[j], buy[j]+p);
            }
        }
        return sell[k-1];
    }
};