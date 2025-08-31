class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 0;
        priority_queue<int>pq;
        for(int i = 0; i<n; i++)
        {
            pq.push(nums[i]);
        }
        while(k > 0)
        {
            int num = pq.top();
            pq.pop();
            score+=num;
            num = (int)ceil((double)num/3.0);
            pq.push(num);
            k--;
        }
        return score;
    }
};