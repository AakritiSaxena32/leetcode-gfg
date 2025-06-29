class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = n/2; i>0; i--)
        {
            int j = 0;
            while(i+j<n && s[j] == s[i+j])
                j++;
            if(i+j == n && s.find(s.substr(0, i-1), j) != string:: npos) return true; 
        }
        return false;
    }
};