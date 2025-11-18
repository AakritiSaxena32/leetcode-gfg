class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();
        string st = "";
        string oneBit = "0";
        string twoBit1 = "10";
        string twoBit2 = "11";
        for(int i = 0 ; i<n; i++)
        {
           st += to_string(bits[i]);
           if(st.compare(oneBit)==0)
           {
                if(i == n-1) return true;
                st = "";
           }
           else if(st.compare(twoBit1) == 0 || st.compare(twoBit2) == 0)
           {
                st = "";
           }
        }
        return false;
    }
};