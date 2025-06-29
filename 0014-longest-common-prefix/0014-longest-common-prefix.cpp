class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int i=0, j=0, n=strs.size();
        if(n==1) return strs[0];
        if(n==0) return "";
        while(i<strs[0].size() && j<strs[1].size())
        {
            if(strs[0][i] == strs[1][j]) prefix += strs[0][i];
            else break;
            i++;
            j++;
        }
        if(prefix == "") return prefix;
        string pre = "";
        for(int k=2; k<n; k++)
        {
            i = 0, j = 0;
            pre = "";
            while(i<strs[k].size() && j<prefix.size())
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
            if(i!=strs[k].size() || j!= prefix.size()) prefix = pre; 
            if(strs[k].size() == 0) return "";
        }
        return prefix;
    }
};