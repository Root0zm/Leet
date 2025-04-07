public class Solution {
    public bool IsPalindrome(string s) {
            s=s.ToLower();
            int i = s.Length -1;
            int j=0;
            while(j<i){
                if((s[i]<'a'|| s[i]>'z')&&(s[i]<'0'||s[i]>'9')) {
                    i--;
                    continue;
                }
                if((s[j]<'a' || s[j]> 'z')&&(s[j]<'0'||s[j]>'9')){
                    j++;
                    continue;
                }
                if(s[j]!=s[i]) return false;
                
                i--;
                j++;
            }
            
            return true;
    }
}