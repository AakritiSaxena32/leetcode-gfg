class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>>pq;
        int cnt_sol = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1) cnt_sol++;
            }
            pq.push({cnt_sol, i});
            if(pq.size() > k){
                pq.pop();
            }
            cnt_sol = 0;
        }
        vector<int> ans;
        while(!pq.empty()){
            auto &it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};