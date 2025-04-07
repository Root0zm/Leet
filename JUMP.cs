public class Solution {
    public bool CanJump(int[] nums) {
         int jump=0;
         for(int i=0;i<nums.Length;i++){
            if(i>jump) return false;
            if(i+nums[i]>jump) jump=i+nums[i];
            
         }
         return true;
    }
}