class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int fm = min(prices[0], prices[1]);
        int sm = max(prices[0], prices[1]);
        for(int i = 2; i<n; i++)
        {
            if(fm > prices[i])
            {
                sm = fm;
                fm = prices[i];
            }
            else if(sm > prices[i])
            {
                sm = prices[i];
            }
        }
        int leftover = fm + sm;
        if(money >= leftover) return money - leftover;
        return money; 
    }
};