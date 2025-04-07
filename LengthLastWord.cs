public class Solution {
    public int LengthOfLastWord(string s) {
        int i=s.Length-1;
        int d=0;
        if(s[i]==' ')
        while(s[i]==' ' && i>=0) i--;
        if(i<=0) return 1;
        while( i>=0 ){
            if(s[i]==' ') break;
            d++;
            i--;
        }
        return d;
    }
}