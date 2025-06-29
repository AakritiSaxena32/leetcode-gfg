class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = b.size();
        string s= "";
        int count = 0;
        while(s.size()<n)
        {
            s+=a;
            count++;
        }
        if(s.find(b) != string::npos)
        {
            return count;
        }
        s+=a;
        count++;
        if(s.find(b) != string::npos)
        {
            return count;
        }
        return -1;
    }
};