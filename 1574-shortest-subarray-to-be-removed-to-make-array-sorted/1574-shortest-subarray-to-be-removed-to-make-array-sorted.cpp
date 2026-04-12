class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        int remove = -1;
        for(int i = 0; i < n-1; i++)
        {
            if(arr[i] <= arr[i+1]) l++;
            else break;
        }
        if(l == n-1) return 0;
        for(int j = n-1; j >= 0; j--)
        {
            if(arr[j-1] <= arr[j]) r--;
            else break;
        }
        remove = min(n-l-1, r);
        for(int i = 0, j = r; i <= l && j < n; )
        {
            if(arr[i] <= arr[j])
            {
                remove = min(j-i-1, remove);
                i++;
            }
            else j++;
        }
        return remove;
    }
};