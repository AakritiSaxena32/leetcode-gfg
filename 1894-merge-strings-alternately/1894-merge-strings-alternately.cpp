class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged="";
        int l1=word1.size(), l2=word2.size();
        int i=0, j=0;
        while(i<l1 && j<l2)
        {
            merged += word1[i];
            merged +=word2[j];
            i++;
            j++;
        }
        while(i<l1)
        {
            merged += word1[i];
            i++;
        }
        while(j<l2)
        {
            merged+=word2[j];
            j++;
        }
        return merged;
    }
};