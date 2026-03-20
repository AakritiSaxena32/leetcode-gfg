class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        vector<string> ans(n, "");
        int i = 0;
        for(auto num: score){
            pq.push({num, i});
            i++;
        }
        int place = 1;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            if(place == 1){
                ans[idx] = "Gold Medal";
            }
            else if(place == 2){
                ans[idx] = "Silver Medal";
            }
            else if(place == 3){
                ans[idx] = "Bronze Medal";
            }
            else{
                ans[idx] = to_string(place);
            }
            place++;
        }
        return ans;
    }
};