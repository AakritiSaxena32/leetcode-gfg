class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n==0 && m!=0) return t[0];
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i=0, j=0;
        char ch;
        while(i<n && j<m)
        {
            if(s[i] != t[i]){
                ch = t[i];
                break; 
            }
            i++;
            j++;
        }
        return ch;
    }
};