public class Solution {
    public int MajorityElement(int[] nums) {
       Dictionary<int,int> a = new Dictionary<int,int>();
       int m=0,r=0;
       for(int i=0;i<nums.Length;i++){
            if(m==0) r=nums[i];
            if(r==nums[i]) m+=1;
            else m-=1;
             
       }
       return r;

    }
    }
