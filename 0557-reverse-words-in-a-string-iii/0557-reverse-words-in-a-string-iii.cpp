class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.size();
        string ans = "";
        string word = "";
        int i = 0;
        while(i < n)
        {
            if(s[i] != ' ') word += s[i];
            else if(s[i] == ' ')
            {
                reverse(word.begin(), word.end());
                ans += word;
                ans += " ";
                word = "";
            }
            i++;
        }
        reverse(word.begin(), word.end());
        ans += word;
        return ans;
    }
};