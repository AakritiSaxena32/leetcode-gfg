class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int j=0, i=0;
        while(i<nums.size())
        {
            if(nums[i]!=0 && nums[j]==0)
            {
                swap(nums[i], nums[j]);
                j++; 
            }
            else if(nums[j]!=0)
            {
                j++;
            }
            i++;
        }
    }
};