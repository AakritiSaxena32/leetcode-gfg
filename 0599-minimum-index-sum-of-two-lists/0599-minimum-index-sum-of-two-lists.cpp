class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size(), m = list2.size();
        unordered_map<string, int> mpp;
        for(int i = 0; i<n; i++)
        {
            mpp[list1[i]] = i;
        }
        int minInd = INT_MAX;
        vector<string> res;
        for(int i = 0; i < m; i++)
        {
            if(mpp.find(list2[i]) == mpp.end()) continue;
            if(minInd > mpp[list2[i]] + i)
            {
                minInd = mpp[list2[i]] + i;
                res.clear();
                res.push_back(list2[i]);
            }
            else if(minInd == mpp[list2[i]] + i)
            {
                res.push_back(list2[i]);
            }
        }
        return res;
    }
};