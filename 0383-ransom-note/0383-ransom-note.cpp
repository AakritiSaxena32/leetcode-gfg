class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        unordered_map<char, int>mpp;
        for(int i = 0; i < n; i++)
        {
            mpp[ransomNote[i]]++;
        }
        for(int i = 0; i < m; i++)
        {
            if(mpp.find(magazine[i]) != mpp.end()) mpp[magazine[i]]--;
            if(mpp[magazine[i]] == 0) mpp.erase(magazine[i]);
        }
        if(mpp.empty()) 
            return true;
        return false;
    }
};