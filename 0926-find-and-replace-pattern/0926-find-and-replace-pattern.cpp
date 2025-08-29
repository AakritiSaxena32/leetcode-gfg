class Solution {
    bool wordPattern(string word, string pattern)
    {
        int n = word.size();
        int m = pattern.size();
        if(n!=m) return false;
        unordered_map<char, char> p2w, w2p;
        for(int i = 0;  i < n; i++)
        {
            char p = pattern[i];
            char w = word[i];

            if((p2w.count(p) && p2w[p] != w) || (w2p.count(w) && w2p[w] != p)) return false;

            p2w[p] = w;
            w2p[w] = p;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<string> res;
        for(int i = 0 ; i < n ;  i++)
        {
            if(wordPattern(words[i], pattern))
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};