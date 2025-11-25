class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 0;
        for(int length = 1; length <= k; length++)
        {
            num = (num*10 + 1) % k;
            if(num == 0)
            {
                return length;
            }
        }
        return -1;
    }
};