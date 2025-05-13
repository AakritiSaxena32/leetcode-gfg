class Solution {
    static bool comp(string &s1, string &s2)
    {
        return s1.size()<s2.size();
    }
    bool checkPossible(string &s1, string &s2)
    {
        if(s1.size() != s2.size()+1) return false;
        int first = 0, second = 0;
        while(first < s1.size())
        {
            if(s1[first] == s2[second] && second < s2.size())
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size())
        {
            return true;
        }
        return false;
    }
public:
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0; i<=n-1; i++)
        {
            for(int j=0; j<=i-1; j++)
            {
                if(checkPossible(words[i], words[j]) && 1+dp[j]>dp[i])
                {
                    dp[i] = 1+dp[j];
                }
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};