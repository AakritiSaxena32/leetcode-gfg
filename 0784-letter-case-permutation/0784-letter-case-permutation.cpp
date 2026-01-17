class Solution {
public:
    void solve(string& ip, int index, string op, vector<string>& res)
    {
        if(index == ip.size())
        {
            res.push_back(op);
            return;
        }

        string op1 = op;
        string op2 = op;

        char ch = ip[index];

        if(isdigit(ch))
        {
            solve(ip, index + 1, op + ch, res);
        }
        else
        {
            op1 += (char)tolower(ch);
            op2 += (char)toupper(ch);
            solve(ip, index+1, op1, res);
            solve(ip, index+1, op2, res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string ip = s;
        string op = "";
        solve(ip, 0, op, res);
        return res;
    }
};