public class Solution {
    public int HIndex(int[] citations) {
        Array.Sort(citations);
        int n= citations.Length-1;
        int h=0;
        while(n>=0){
            if(citations[n]>h) h++;
            n--;
        }
        return h;
    }
}