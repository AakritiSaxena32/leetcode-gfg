class Solution {
    int canMakeBouquet(vector<int>&bloomDay, int mid, int k)
    {
        int n = bloomDay.size();
        int bouquet = 0, count = 0;
        for(int i = 0; i<n; i++)
        {
            if(bloomDay[i] <= mid) 
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if(count == k)
            {
                bouquet++;
                count = 0;
            }
        }
        return bouquet;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start_day = 0;
        int end_day = *max_element(begin(bloomDay), end(bloomDay));
        int minDays = -1;
        while(start_day <= end_day)
        {
            int mid = start_day + (end_day - start_day)/2;
            if(canMakeBouquet(bloomDay, mid, k) >= m)
            {
                minDays = mid;
                end_day = mid - 1;
            }
            else
            {
                start_day = mid + 1;
            }
        }
        return minDays;
    }
};