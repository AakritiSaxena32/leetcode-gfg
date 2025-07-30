class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n = s.size(), i = 0, j = 0, maxi = 0;
        unordered_map<int,int> mpp;
        while(j<n)
        {
            mpp[s[j]]++;
            if(mpp.size() <= 2)
            {
                maxi = max(maxi, j-i+1);
            }
            else if(mpp.size() > 2)
            {
                while(mpp.size() > 2)
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0)
                    {
                        mpp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};