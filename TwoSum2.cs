public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int n=numbers.Length-1;
        for(int i=0;i<=n;i++){
            if(numbers[i]+numbers[n]<target)
                continue;
            if(numbers[i]+numbers[n]>target){
                n--;i--;
                continue;
            }
            if(numbers[i]+numbers[n]==target)
                return new int[] {i+1,n+1};
        }
        return new int[] {0};
    }
    
}