class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>> vowels;
        string t = "";
        for(char ch: s)
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I')
            {
                vowels.push(ch);
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U' || s[i] == 'I'))
            {
                t += s[i];
            }
            else
            {
                t += vowels.top();
                vowels.pop();
            }
        }
        return t;
    }
};