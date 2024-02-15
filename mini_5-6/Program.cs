public class program
{

    static void Main(string[] args)
    {
        Console.Write("Enter the number elements of array : ");
        int numbers = Convert.ToInt32(Console.ReadLine());
        int[] arr = new int[numbers];
        for (int i = 0; i < numbers; i++) {
            Console.Write("Enter the number " + i+ "'th element: ");
            arr[i] = Convert.ToInt32(Console.ReadLine()); ; 
        }
        int[] arr2 = mini_6.WiggleSort(arr);
        Console.Write("Result of WiggleSort: ");
        for (int i = 0;i < arr2.Length;i++) {
            Console.Write(arr2[i] + " ");
        }
        Console.WriteLine("\n Result Hirsch index: " + mini_5.HIndex(arr));


    }
}



