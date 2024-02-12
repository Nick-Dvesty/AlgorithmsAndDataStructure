public class Mini_3
{
    public static void start()
    {
        Console.Write("Введите длину массива: ");
        int a = Convert.ToInt32(Console.ReadLine());
        int[] s = new int[a];
        Console.WriteLine("Введите элементы массива");
        for (int i = 0; i < a; i++) {
            s[i] = Convert.ToInt32(Console.ReadLine());
        }
        Console.Write("Введите искомое число: ");
        int b = Convert.ToInt32(Console.ReadLine());
        int c = Min_3(s, b);
        if (c != 0) Console.WriteLine("Число " + b + " находиться на позиции " + c);
        else Console.WriteLine("Элемент не найден");
    }
    static int Min_3(int[] arg, int find_element)
    {
        int up = arg.Length;
        int down = 1;
        int middle;
        for (int i = 0; i <= Math.Log2(arg.Length) + 1; i++) {
            middle = (up + down) / 2;
            if (arg[middle - 1] == find_element) return middle;
            if (arg[middle - 1] < find_element) down += (up - down + 1) / 2;
            if (arg[middle - 1] > find_element) up -= (up - down + 1) / 2;

        }
        return 0;
    }
}  
