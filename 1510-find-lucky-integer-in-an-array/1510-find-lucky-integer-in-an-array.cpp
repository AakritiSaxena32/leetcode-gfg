class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int, int> mpp;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            if(!mpp[arr[i]]) mpp[arr[i]] = 0;
            mpp[arr[i]]++;
        }
        int max = -1;
        for(auto it: mpp)
        {
            int first = it.first;
            int second = it.second;
            if(max<first)
            {
                if(first == second)
                {
                    max = first;
                }
            }
        }
        return max;
    }
};