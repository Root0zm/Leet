<<<<<<< HEAD
public class Solution {
    public bool IsSubsequence(string s, string t) {
        int n=s.Length;
        int m=t.Length;
        int j=0;
        if(s== "" ) return true;
        
        for(int i=0;i<m;i++){
           if(t[i]==s[j]){
                j++;
               
           }
           if(j==n) return true;
                   
        }
        return false;
    }
=======
public class Solution {
    public bool IsSubsequence(string s, string t) {
        int n=s.Length;
        int m=t.Length;
        int j=0;
        if(s== "" ) return true;
        
        for(int i=0;i<m;i++){
           if(t[i]==s[j]){
                j++;
               
           }
           if(j==n) return true;
                   
        }
        return false;
    }
>>>>>>> 593883a68b790a105e4bb47aa97aafdc4402fe60
}