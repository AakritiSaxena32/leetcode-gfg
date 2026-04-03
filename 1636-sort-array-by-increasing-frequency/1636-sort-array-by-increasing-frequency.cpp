class Solution {
    struct cmp
    {
        bool operator()(pair<int, int>&a, pair<int, int>&b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        typedef pair<int, int>p;
        priority_queue<p, vector<p>, cmp>pq;
        unordered_map<int, int> mp;
        for(int i: nums)
        {
            mp[i]++;
        }
        vector<int>res;
        for(auto& it: mp)
        {
            pq.push({it.second, it.first});
        }
        while(!pq.empty())
        {
            int freq = pq.top().first;
            while(freq--) res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};