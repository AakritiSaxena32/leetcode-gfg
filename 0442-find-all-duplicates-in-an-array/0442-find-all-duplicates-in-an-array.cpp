class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // vector<int> result;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     freq[nums[i]]++;
        // }
        // for(auto & i : freq)
        // {
        //     if(i.second>1)
        //     {
        //         result.push_back(i.first);
        //     }   
        // }
        // return result;



        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<int> ans;
        while(i<n-1)
        {
            if(nums[i] == nums[i+1])
            {
                ans.push_back(nums[i]);
                i = i + 2;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};