class Solution {
    bool Palindrome (string s)
    {
        int n = s.size();
        int i = 0, j = n-1;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string news = "";
        if(n==0) return true;
        for(int i = 0; i < n; i++)
        {
            if(isalnum(s[i]))
            {
                news += tolower(s[i]);
            }
        }
        return Palindrome(news);
    }
};