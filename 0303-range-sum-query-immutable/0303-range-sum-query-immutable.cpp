class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pref.resize(n);
        pref[0] = nums[0];
        for(int i = 1; i< n; i++)
        {
            pref[i] = pref[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return (pref[right] - ((left-1 >= 0)?pref[left-1]: 0));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */