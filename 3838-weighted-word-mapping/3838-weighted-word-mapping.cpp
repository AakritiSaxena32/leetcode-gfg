class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans;
        for(string w: words)
        {
            long long sum = 0;
            for(char ch : w)
            {
                sum += weights[ch - 'a'];
            }
            ans.push_back('z' - (sum % 26));
        }
        return ans;
    }
};