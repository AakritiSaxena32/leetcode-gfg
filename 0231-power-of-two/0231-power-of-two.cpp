class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        long long num = 1;
        while(num <= n)
        {
            if(num == n)
            {
                return true;
            }
            num *= 2;
        }
        return false;
    }
};