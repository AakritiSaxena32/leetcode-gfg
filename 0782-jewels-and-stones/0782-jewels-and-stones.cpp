class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int m = jewels.size(), n = stones.size();
        unordered_set<char> freq;
        for(char &ch: jewels)
        {
            freq.insert(ch);
        }
        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(freq.find(stones[i]) != freq.end()) count++;
        }
        return count;
    }
};