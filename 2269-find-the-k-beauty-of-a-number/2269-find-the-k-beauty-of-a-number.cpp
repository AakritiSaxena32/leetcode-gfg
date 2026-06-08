class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int i = 0, j = 0;
        int beauty = 0;
        string div = "";
        while(j < n)
        {
            if(j-i+1 == k)
            {
                string sub = s.substr(i,k);
                int div = stoi(sub);
                if(div != 0 && num % div == 0)
                {
                    beauty++;
                }
                i++;
            }
            j++;
        }
        return beauty;
    }
};