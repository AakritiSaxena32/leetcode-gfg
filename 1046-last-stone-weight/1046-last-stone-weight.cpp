class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> max_heap;
        for(int i = 0; i < n; i++)
        {
            max_heap.push(stones[i]);
        }
        while(max_heap.size() > 1 && !max_heap.empty())
        {
            int first_max = max_heap.top();
            max_heap.pop();
            int second_max = max_heap.top();
            max_heap.pop();
            int diff = first_max - second_max;
            if(diff > 0){
                max_heap.push(diff);
            }
        }
        return max_heap.empty()? 0 : max_heap.top();
    }
};