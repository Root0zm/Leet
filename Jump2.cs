public class Solution {
    public int Jump(int[] nums) {
        int jum = 0,count = 0,cur = 0;
        for(int i=0;i<nums.Length-1;i++){
            
            if(i+nums[i] > jum){
                
                jum = i+nums[i];
               
            }
            
            if(i == cur)
            {
                count ++;
                cur= jum;
                
            }
            
        }
        return count;
            
    }
}