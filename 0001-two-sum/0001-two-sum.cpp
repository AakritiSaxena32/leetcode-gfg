class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map <int, int> mpp;
        for(int i = 0 ; i < n ; i++)
        {
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded) != mpp.end()) // mpp.find(moreNeeded) returns an iterator to the key-value pair in the map mpp where the key matches moreNeeded.
                return {mpp[moreNeeded], i};
            mpp[num] = i;
        }
        return {-1, -1};

    }
};

// If the key is found, it returns an iterator to the position where the key is present in the map.
// If the key is not found, it returns an iterator to the end of the map.