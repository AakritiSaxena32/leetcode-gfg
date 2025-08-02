class Solution {
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length();
        if(m>n) return "";
        unordered_map <char, int> mpp;
        for(char &ch: t)
        {
            mpp[ch]++;
        }
        int requiredCount = m;
        int i=0 ,j=0;
        int windowSize = INT_MAX;
        int start_i = 0;
        while(j<n)
        {
            char ch = s[j];
            if(mpp[ch] > 0) requiredCount--;
            mpp[ch]--;
            while(requiredCount == 0)
            {
                int currWindowSize = j-i+1;
                if(windowSize > currWindowSize)
                {
                    windowSize = currWindowSize;
                    start_i = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0)
                {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return windowSize == INT_MAX? "":s.substr(start_i, windowSize);
    }
};