class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char last;
        for(int i = 1; i < n; i++)
        { 
            if(sentence[0] != sentence[n-1]) return false; 
            if(sentence[i] == ' ')last = sentence[i-1];
            if(sentence[i] == ' ' && last != sentence[i+1 % n]) return false;
        }
        return true;
    }
};