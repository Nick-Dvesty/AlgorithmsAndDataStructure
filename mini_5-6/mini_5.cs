public class mini_5
{
    static readonly int[] SheelSequence = { 1, 4, 10, 23, 57, 132, 301, 701 };

    public static int HIndex(int[] citations)
    {
        citations = SheelSort(citations);
        int o = 0;
        for (int i = 0; i < citations.Length; i++)
        {
            if (citations[i] >= i + 1) o++;
        }
        return o;
    }
    public static int[] SheelSort(int[] nums)
    {
        for (int i = SheelSequence.Length - 1; i >= 0; i--)
        {

            for (int j = 0; j < SheelSequence[i]; j++)
            {
                nums = InsertSort(nums, j, SheelSequence[i]);
            }
        }
        return nums;
    }
    public static int[] InsertSort(int[] nums, int StartIndex, int step)
    {
        for (int i = StartIndex; i < nums.Length; i += step)
        {
            int j;
            int key = nums[i];
            for (j = i - step; j >= 0 && nums[j] < key; j -= step)
            {

                nums[j + step] = nums[j];
            }
            nums[j + step] = key;
        }
        return nums;
    }

}
