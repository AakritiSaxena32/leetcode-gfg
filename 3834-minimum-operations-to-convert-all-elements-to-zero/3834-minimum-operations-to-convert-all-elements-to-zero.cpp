class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        vector<int> st;
        int count = 0;
        for(int num: nums)
        {
            while(!st.empty() && st.back() > num) st.pop_back();
            if(num == 0) continue;
            if(st.empty() || st.back() < num) 
            {
                count++;
                st.push_back(num);
            }
        }
        return count;
    }
};