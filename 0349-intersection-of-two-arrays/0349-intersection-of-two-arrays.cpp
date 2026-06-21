class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>seen;
        vector<int> ans;
        for(int i: nums1)
        {
            seen.insert(i);
        }
        for(int i: nums2)
        {
            if(seen.count(i))
            {
                ans.push_back(i);
                seen.erase(i);
            }
        }
        return ans;
    }
};