class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.size();
        // for(int i = n/2; i>0; i--)
        // {
        //     int j = 0;
        //     while(i+j<n && s[j] == s[i+j])
        //         j++;
        //     if(i+j == n && s.find(s.substr(0, i-1), j) != string:: npos) return true; 
        // }
        // return false;

        int len = s.size();
        int size = 1;
        while(size<=len/2)
        {
            if(len % size != 0)
            {
                size++;
                continue;
            }
            bool canConstruct = true;
            for(int i = size; i<len; i++)
            {
                if(s[i] != s[i%size])
                {
                    canConstruct = false;
                    break;
                }
            }
            if(canConstruct) return true;
            size++;
        }
        return false;
    }
};