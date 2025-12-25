class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;

        int totalSum = 0;
        while(i <= n)
        {
            totalSum += i;
            i++;
        }

        int leftSum = 0;
        for(int i = 1; i <= n; i++)
        {
            leftSum += i;
            int rightSum = totalSum - leftSum + i; 
            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};