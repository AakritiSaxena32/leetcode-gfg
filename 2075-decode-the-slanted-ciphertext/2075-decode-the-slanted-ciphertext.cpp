class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if(n == 0) return "";
        int cols = n / rows;
        string res = "";
        for(int st = 0; st < cols; st++)
        {
            int i = 0, j = st;
            while(i < rows && j < cols)
            {
                res += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
        while(!res.empty() && res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};