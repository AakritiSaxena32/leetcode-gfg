class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        while(left <= right)
        {
            int num = left;
            bool flag = false;
            while(num > 0)
            {
                int rem = num % 10;
                if(rem != 0 && left % rem == 0)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
                num /= 10;
            }
            if(flag == true)
            {
                ans.push_back(left);
            }
            left++;
        }
        return ans;
    }
};