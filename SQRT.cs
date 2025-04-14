public class Solution {
    public int MySqrt(int x) {
        if(x<2) return x;
        int l=0,r = x/2 +1 ;
        while(l<=r){
            int m= (l+r)/2;
            long sq=(long) m*m;
            if(sq == x ) return m;
            else if(sq<x) l=m+1;
            else r=m-1;
        }
        return r;
    }
}