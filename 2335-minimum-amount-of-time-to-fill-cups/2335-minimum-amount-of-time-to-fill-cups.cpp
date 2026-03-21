class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        sort(amount.begin(), amount.end());
        while(amount[1] && amount[2]){
            ans++;
            amount[1]--;
            amount[2]--;
            sort(amount.begin(), amount.end());
        }
        ans += amount[2]; 
        return ans;
    }
};