class TwoSum
{
    public int[] twoSum(int[] nums, int target)
    {
        int length = nums.length();
        int current = 0;
        while (current != length)
        {
            int nextInt = current;
            while (nextInt != length)
            {
                if (nums[current] + nums[nextInt] == target)
                {
                    return [current, target];
                }
                else
                {
                    nextInt++;
                }
            }
            current++;
        }
    }
}
