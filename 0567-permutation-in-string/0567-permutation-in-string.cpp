class Solution {
    bool countzeroes(vector<int>counter)
    {
        for(int&i : counter)
        {
            if(i!=0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        vector<int>counter(26,0);
        for(int i = 0; i<m; i++)
        {
            counter[s1[i] - 'a']++;
        }
        int i = 0, j = 0;
        while(j<n)
        {
            counter[s2[j] - 'a']--;
            while(j-i+1 == m)
            {
                if(countzeroes(counter))
                {
                    return true;
                }
                counter[s2[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false;
    }
};