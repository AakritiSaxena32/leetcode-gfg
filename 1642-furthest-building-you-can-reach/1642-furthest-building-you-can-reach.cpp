class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for(i = 0 ; i < n-1 ; i++)
        {
            if(heights[i+1] < heights[i]) continue;
            int diff = heights[i+1] - heights[i];
            if(diff <= bricks)
            {
                bricks -= diff;
                pq.push(diff);
            } 
            else if(ladders > 0)
            {
                if(!pq.empty())
                {
                    int max_past_bricks = pq.top();
                    if(diff < max_past_bricks)
                    {
                        pq.pop();
                        bricks += max_past_bricks;
                        bricks -= diff;
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else
            {
                break;
            }
        }
        return i;
    }
};