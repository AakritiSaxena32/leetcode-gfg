class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> hash(256, -1);
        // int l=0, r=0, maxlen=0, n=s.size();
        // while(r<n)
        // {
        //     if(hash[s[r]]!=-1)
        //     {
        //         if(hash[s[r]]>=l)
        //         {
        //             l=hash[s[r]]+1;
        //         }
        //     }
        //     int len=r-l+1;
        //     maxlen=max(len, maxlen);
        //     hash[s[r]]=r;
        //     r++;
        // }
        // return maxlen;

        int n = s.size(), i=0, j=0, maxi = 0;
        unordered_map <char, int> mpp;
        while(j<n)
        {
            mpp[s[j]]++;
            if(mpp.size() == j-i+1)
            {
                maxi = max(maxi, j-i+1);
            }
            else if(mpp.size() < j-i+1)
            {
                while(mpp.size() < j-i+1)
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0)
                    {
                        mpp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};