class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){return positions[a] < positions[b];});
        vector<bool> alive(n, true);
        vector<int> st;
        for(int& idx: order)
        {
            if(directions[idx] == 'R') st.push_back(idx);
            else
            {
                while(!st.empty())
                {
                    int top = st.back();
                    if(healths[idx] > healths[top])
                    {
                        alive[top] = false;
                        st.pop_back();
                        healths[idx]--;
                    }
                    else if(healths[idx] < healths[top])
                    {
                        alive[idx] = false;
                        healths[top]--;
                        break;
                    }
                    else
                    {
                        alive[idx] = false;
                        alive[top] = false;
                        st.pop_back();
                        break;
                    }
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(alive[i]) res.push_back(healths[i]);
        }
        return res;
    }
};