public class Mini_2
{
    public static void start()
    {
        Console.Write("Введите множитель: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.Write("Введите множитель: ");
        int b = Convert.ToInt32(Console.ReadLine());
        int c = Min_2(a, b);
        Console.WriteLine("Произведение: " + c);
    }

    static int Min_2(int int_a, int int_b)
    {
        int sign = ((int_a >>> 31) ^ (int_b >>> 31)) == 1 ? -1 : 1;
        int_a = int_a < 0 ? (int_a ^ -1) + 1 : int_a;
        int_b = int_b < 0 ? (int_b ^ -1) + 1 : int_b;
        if (int_a < 2 && int_b < 2) return int_a & int_b;
        else
        {
            int min = int_a <= int_b ? int_a : int_b;
            int max = int_a > int_b ? int_a : int_b;
            int shift = 0;
            for (int i = max; i != 0; i >>= 1) shift++;
            if ((shift & 1) == 1) shift++;
            int a = max >> (shift / 2);
            int b = max - (a << shift / 2);
            int c = min >> (shift / 2);
            int d = min - (c << shift / 2);
            int int1 = Min_2(a, c);
            int int2 = Min_2(b, d);
            int int3 = Min_2(a + b, c + d) - int1 - int2;
            return ((int1 << shift) + (int3 << shift / 2) + int2) * sign;
        }
    }
}