class Solution {
    int customBeautySearch(vector<vector<int>>& items, int query)
    {
        int l = 0, h = items.size()-1;
        int mid;
        int maxBeauty = 0;
        while(l<=h)
        {
            mid = l + (h-l)/2;
            if(items[mid][0] > query)
            {
                h = mid - 1;
            }
            else
            {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid + 1;
            }
        }
        return maxBeauty;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        int n = items.size();
        int m = queries.size();

        vector<int> res(m);

        sort(items.begin(), items.end());
        int maxBeauty = 0;
        for(int i = 0; i<n; i++)
        {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for(int  i = 0; i<m; i++)
        {
            res[i] = customBeautySearch(items, queries[i]);
        }
        return res;
    }
};