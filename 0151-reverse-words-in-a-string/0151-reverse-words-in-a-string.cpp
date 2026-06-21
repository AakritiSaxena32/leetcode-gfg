class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        int n = s.size();
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ')
            {
                if(word.size() > 0)
                {
                    reverse(word.begin(), word.end());
                    res += word;
                    res += ' ';
                    word = "";
                }
            }
            else
            {
                word += s[i];
            }
        }
        reverse(word.begin(), word.end());
        res += word;
        n = res.size();
        if(res[n-1] == ' ') res.pop_back();
        return res;
    }
};