class Solution {
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above)
    {
        if(curr.length() == 1)
        {
            return true;
        }
        if(idx == curr.length()-1)
        {
            return solve(above, mp, 0, "");
        }
        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end())
        {
            return false;
        }
        for(char &ch: mp[pair])
        {
            above.push_back(ch);
            if(solve(curr, mp, idx+1, above) == true) return true;
            above.pop_back();
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(auto& pattern : allowed)
        {
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }
        return solve(bottom, mp, 0, "");
    }
};