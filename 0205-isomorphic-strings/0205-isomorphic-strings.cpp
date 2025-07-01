class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        int n = s.size();
        int i = 0, j = 0;
        while(i<n && j<n)
        {
            if(m1[s[i]] && m1[s[i]] != t[i]) return false;
            if(m2[t[i]] && m2[t[i]] != s[i]) return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
            i++;
            j++;
        }
        return true;
    }
};