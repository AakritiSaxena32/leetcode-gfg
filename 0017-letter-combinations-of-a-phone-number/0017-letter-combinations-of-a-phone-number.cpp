class Solution {
    vector<string> ans;
    void solve(int idx, string &digits, string &temp, map<char, string> &mpp)
    {
        if(idx == digits.size()) 
        {
            ans.push_back(temp);
            return;
        }
        for(char letter: mpp[digits[idx]])
        {
            temp += letter;
            solve(idx+1, digits, temp, mpp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        map<char, string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string temp = "";
        solve(0, digits, temp, mpp);
        return ans;
    }
};