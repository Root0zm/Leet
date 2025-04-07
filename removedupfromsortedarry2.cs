public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int k =1;
        int d=0;
        for(int i=1;i<nums.Length;i++){
            if(nums[i]==nums[i-1]) d++;
            if(nums[i]!=nums[i-1]) d=0;
            if(nums[i]!=nums[i-1]||d==1){
                nums[k]=nums[i];
                k++;
            }
              
        }
        return k;
    }
}