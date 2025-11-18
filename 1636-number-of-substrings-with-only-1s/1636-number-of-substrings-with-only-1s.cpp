class Solution {
public:
    int numSub(string s) 
    {
        int total = 0, cnt = 0, mod = 1e9 + 7;
        for(char a: s)
        {
            if(a == '1')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            total = (total + cnt) % mod;
        }
        return total;
    }
};