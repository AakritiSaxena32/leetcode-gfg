class Solution {
    int newNumber(int n)
    {
        int newNum = 0;
        while(n != 0)
        {
            int rem = n % 10;
            newNum += pow(rem, 2);
            n = n/10;
        }
        return newNum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        while(visit.find(n) == visit.end())
        {
            visit.insert(n);
            n = newNumber(n);
            if(n == 1) return true;
        }
        return false;
    }
};