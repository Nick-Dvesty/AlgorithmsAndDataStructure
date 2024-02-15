
public static class mini_6
{
    public static int[] WiggleSort(int[] nums)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            int key = nums[i];
            int j;
            for (j = i - 1; j >= 0 && nums[j] > key; j--)
            {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = key;
        }
        int[] result = new int[nums.Length];

        for (int i = 0; i < (nums.Length + 1) / 2; i++)
        {
            result[2 * i] = nums[nums.Length - nums.Length / 2 - 1 - i];
            if ((2 * i) + 1 < nums.Length) result[(2 * i) + 1] = nums[nums.Length - 1 - i];
        }
        nums = result;
        return nums;
    }
}