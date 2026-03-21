class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<float, int>>pq;
        float dist = 0;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            dist = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({dist, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto & it = pq.top();
            ans.push_back(points[it.second]);
            pq.pop();
        }
        return ans;
    }
};