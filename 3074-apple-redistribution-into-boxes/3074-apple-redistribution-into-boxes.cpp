class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int totalApples = 0;
        for(int i: apple)
        {
            totalApples += i;
        }
        int cnt = 0;
        for(int i: capacity)
        {
            totalApples -= i;
            cnt++;
            if(totalApples <= 0) break;
        }
        return cnt;
    }
};