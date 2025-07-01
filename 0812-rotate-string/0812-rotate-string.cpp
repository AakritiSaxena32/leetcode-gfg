class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n!=m) return false;
        string concate = goal + goal;
        if(concate.find(s) != string::npos)
        {
            return true;
        }
        return false;
    }
};