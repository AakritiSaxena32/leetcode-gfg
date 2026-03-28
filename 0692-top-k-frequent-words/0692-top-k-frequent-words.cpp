class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int>freq;
        for(string &w: words){
            freq[w]++;
        }
        auto cmp =[](pair<int, string>&a, pair<int, string>&b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for(auto& it: freq){
            pq.push({it.second, it.first});
        }
        vector<string> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};