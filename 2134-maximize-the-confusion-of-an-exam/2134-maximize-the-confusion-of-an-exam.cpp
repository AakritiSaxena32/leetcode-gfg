class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int n = answerKey.size();
        int i = 0, j = 0, result = 0;
        unordered_map<char, int> mpp;
        while(j<n)
        {
            mpp[answerKey[j]]++;
            while(min(mpp['T'], mpp['F']) > k)
            {
                mpp[answerKey[i]]--;
                i++;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
};