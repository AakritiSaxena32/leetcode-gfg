class Solution {
    bool allZeroes(vector<int>counter)
    {
        for(auto& i: counter)
        {
            if(i != 0)
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n = s.size();
        int m = p.size();
        vector<int> counter(26, 0);
        for(auto &ch: p)
        {
            counter[ch - 'a']++;
        }
        vector<int> result;
        int i = 0, j = 0;
        while(j < n)
        {
            counter[s[j] - 'a']--;
            if(j-i+1 == m)
            {
                if(allZeroes(counter))
                {
                    result.push_back(i);
                }
                counter[s[i] - 'a']++;
                i++;
            }
            j++;
        } 
        return result;
    }
};