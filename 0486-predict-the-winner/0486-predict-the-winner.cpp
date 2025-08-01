class Solution {
    int score_calc(int i, int j, vector<int>&nums)
    {
        if(i>j) return 0;
        if(i==j) return nums[i];
        int take_i = nums[i] + min(score_calc(i+2, j, nums), score_calc(i+1, j-1, nums));
        int take_j = nums[j] + min(score_calc(i+1, j-1, nums), score_calc(i, j-2, nums));
        return max(take_i, take_j);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(begin(nums), end(nums), 0);
        int p1_score = score_calc(0, n-1, nums);
        int p2_score = total_sum - p1_score;
        return (p1_score >= p2_score)? true: false;
    }
};