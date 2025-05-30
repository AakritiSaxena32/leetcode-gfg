class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n=ratings.size(), peak, down, i=1, candy=n;
    while(i<n)
    {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }
        peak=0;
        while(ratings[i]>ratings[i-1])
        {
            peak++;
            candy+=peak;
            i++;
            if(i==n)
            {
                return candy;
            }
        }
        down=0;
        while(i<n && ratings[i]<ratings[i-1])
        {
            down++;
            candy+=down;
            i++;
        }
        candy-=min(peak,down);
    }
        return candy;
    }
};