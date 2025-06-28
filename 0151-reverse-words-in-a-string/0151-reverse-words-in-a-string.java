class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        StringBuffer sb = new StringBuffer(s);
        sb.reverse();
        s = sb.toString();
        String [] arr = s.split("\\s+");
        int n = arr.length;
        String res="";
        for(int i=0; i<n; i++)
        {
            StringBuffer ss = new StringBuffer(arr[i]);
            ss.reverse();
            if(i!=n-1)
                res += ss.toString() + " ";
            else
                res += ss.toString();
        }
        return res;
    }
}