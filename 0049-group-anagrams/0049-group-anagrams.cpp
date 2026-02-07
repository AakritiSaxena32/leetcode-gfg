class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>>mpp;
        for(string i: strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(i);
        }
        for(auto a: mpp)
        {
            res.push_back(a.second);
        }
        return res;
    }
};