class Solution {
    void computeLPS(vector<int>& lps, string needle)
    {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while(i<needle.size())
        {
            if(needle[i] == needle[length])
            {
                length++;
                lps[i] = length;
                i++;
            }
            else
            {
                if(length != 0)
                {
                    length = lps[length-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0, j = 0;
        vector<int> lps(m);
        computeLPS(lps, needle);

        while(i<n)
        {
            if(needle[j] == haystack[i])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return i-j;
            }
            else if(i<n && needle[j] != haystack[i])
            {
                if(j!=0)
                {
                    j = lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};