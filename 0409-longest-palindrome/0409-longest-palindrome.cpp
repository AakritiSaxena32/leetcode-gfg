class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int oddfreq = 0, len = 0;
        for(int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
            if(mpp[s[i]]%2==1)
            {
                oddfreq++;
            }
            else
            {
                oddfreq--;
            }
        }
        if(oddfreq>0)
        {
            return n - oddfreq + 1;
        }
        return n;
    }
};