class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        int n = s.size();
        unordered_map<char, int> mpp;
        int cnt = 0, i = 0, j = 0;
        while(j<n)
        {
            mpp[s[j]]++;
            if(j-i+1 == 3)
            {
                if(mpp.size() == 3) cnt++;
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};
