class FindSumPairs {
    vector<int> n1, n2;
    unordered_map<int, int> mpp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(auto it: n2)
        {
            mpp[it] ++;
        }
    }
    
    void add(int index, int val) {
        int old = n2[index];
        int newVal = old + val;
        mpp[old]--;
        if(mpp[old] == 0)
        {
            mpp.erase(old);
        }
        n2[index] = newVal;
        mpp[newVal]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto it: n1)
        {
            int comp = tot - it;
            if(mpp.count(comp)) cnt += mpp[comp];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */