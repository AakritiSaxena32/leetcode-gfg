class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                ans += s[i] + 32;
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};