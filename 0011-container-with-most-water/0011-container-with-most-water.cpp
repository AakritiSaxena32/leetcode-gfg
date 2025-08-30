class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmt = INT_MIN;
        int n = height.size();
        int i=0, j=n-1;

        while(i<=j) 
        {
           int width = j - i;
           int h = min(height[i], height[j]);
           int area  = width * h;
           maxAmt = max(area, maxAmt);
           if(height[i] < height[j])    i++;
           else                         j--;
        }
        return maxAmt;
    }
};