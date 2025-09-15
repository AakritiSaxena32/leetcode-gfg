class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>>ans;
        for(int i = 0; i <= subset-1; i++)
        {
            vector<int> list;
            for(int num = 0; num<n; num++)
            {
                if(i & (1<<num))
                {
                    list.push_back(nums[num]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};