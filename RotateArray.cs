public class Solution {
    public void Rotate(int[] nums, int k) {
        int n=nums.Length;
         k=k%n;
     
        
        Reverse(nums,0,n-1);
        Reverse(nums,0,k-1);
        Reverse(nums,k,n-1);

    }
    public void Reverse(int[] nums, int s,int e){
        while (s<e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            e--;s++;

        }
    } 
}
