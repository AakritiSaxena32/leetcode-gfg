;class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        int maxnum = 0;
        vector<int> res;
        for(int i = 0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto & it: mpp)
        {
            pq.push({it.second, it.first});
        }
        while(k-- && !pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};