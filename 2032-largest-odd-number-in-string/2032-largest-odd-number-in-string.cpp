class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int i = n;
        string res = "";
        while(i>=0)
        {
            if((num[i]-'0')%2!=0)
            {
                return res = num.substr(0, i+1);
            }
            i--;
        }
        return res;
    }
};