

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> mang = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length;i++)
        {
            int tg = target - nums[i];
            if(mang.ContainsKey(tg))
            {
                return new int[] {mang[tg],i};
            }
            mang[nums[i]] = i;
        }
        return new int[] {0,0};
    }
} 
