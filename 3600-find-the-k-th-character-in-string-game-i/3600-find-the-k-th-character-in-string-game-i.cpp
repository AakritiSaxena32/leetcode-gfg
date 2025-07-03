class Solution {
public:
    char kthCharacter(int k)
    {
        string word = "a";
        while(word.length()<k)
        {
            int n = word.length();
            for(int j=0; j<n && word.length()<k; j++)
            {
                char ch = word[j] + 1;
                if(ch<='z')
                {
                    word+=ch;
                }
            }
        }
        return word[k-1];
    }
};