public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        Dictionary<char,int> count = new Dictionary<char,int>();
        foreach(char c in magazine){
            if(count.ContainsKey(c)) count[c]++;
            else count[c]=1;
        }
        foreach(char c in ransomNote){
            if(!count.ContainsKey(c)|| count[c]==0)
                return false;
            count[c]--;
        }
        return true;
    }
}