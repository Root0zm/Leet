public class Solution {
    public int MaxProfit(int[] prices) {
        int min= 100000;
        int prof=0;
        for(int i=0;i<prices.Length;i++){
            if(prices[i]<min) min = prices[i];
            int profit= prices[i]-min;
            if(profit > prof ) prof = profit;
        }
        return prof;
    }
}