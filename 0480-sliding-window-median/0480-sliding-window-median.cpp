class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> u, l;
        int n = nums.size();
        for(int i = 0; i< n; i++)
        {
            if(u.empty() || nums[i] >= *u.begin())
                u.insert(nums[i]);
            else l.insert(nums[i]);

            if(i >= k)
            {
                if(nums[i-k] >= *u.begin())
                    u.erase(u.find(nums[i-k]));
                else l.erase(l.find(nums[i-k]));
            }

            while(u.size() < l.size())
            {
                u.insert(*l.rbegin());
                l.erase(--l.end());
            }
            while(u.size() > l.size()+1)
            {
                l.insert(*u.begin());
                u.erase(u.begin());
            }
            if(i >= k-1)
            {
                if(k & 1)res.push_back(*u.begin());
                else res.push_back(((double)*u.begin() + *l.rbegin())/2);
            }
        }
        return res;
    }
};