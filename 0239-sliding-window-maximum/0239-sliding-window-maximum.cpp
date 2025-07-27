class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> deq;
        for(int i=0; i<n; i++)
        {
            while(!deq.empty() && deq.front() <= i-k)
            {
                deq.pop_front();
            }
            while(!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= k-1)
            {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};