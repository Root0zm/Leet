public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int g=0,c=0;
        int s=0;
       
        int t=0;int j=0,tam=0;
        for(int i=0;i<gas.Length;i++){
            g += gas[i];
            c += cost[i];
            t += gas[i]-cost[i];
            if(t<0){
                s=i+1; t=0;
            }
        }
        if(g>=c) return s;
        else return -1;
    }
}