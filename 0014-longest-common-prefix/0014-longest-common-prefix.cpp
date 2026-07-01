class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];
        if(n == 0) return "";
        string prefix = "";
        string pre = "";
        int i = 0;
        int j = 0;
        while(i < strs[0].size() && j < strs[1].size())
        {
            if(strs[0][i] == strs[1][j]) prefix += strs[0][i];
            else break;
            i++;
            j++;
        }
        if(prefix == "") return "";
        for(int k = 2; k < n; k++)
        {
            int i = 0, j = 0;
            pre = "";
            while(i < strs[k].size() && j < prefix.size())
            {
                if(strs[k][i] == prefix[j])
                {
                    pre += strs[k][i];
                }
                else
                {
                    prefix = pre;
                    break;
                }
                i++;
                j++;
            }
            if(i != strs[k].size() || j != prefix.size()) prefix = pre;
            if(strs[k].size() == 0) return ""; 
        }
        return prefix;
    }
};