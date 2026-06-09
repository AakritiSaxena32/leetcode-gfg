class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();

        vector<int> res(n, 0);
        if(k==0) return res;
        int i = -1, j = -1;
        if(k>0)
        {
            i = 1;
            j = k;
        }
        else
        {
            i = n - abs(k);
            j = n-1;
        }
        
        int windowSum = 0;
        int pointer = i;
        while(pointer<=j)
        {
            windowSum += code[pointer];
            pointer++;
        }
        for(int k = 0; k<n; k++)
        {
            res[k] = windowSum;
            windowSum -= code[i%n];
            i++;
            windowSum += code[(j+1)%n];
            j++;
        }
        return res;
    }
};