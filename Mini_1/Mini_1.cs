public class Mini_1
{
    public static void start()
    {
        Console.Write("Введите делимое: ");
        int a = Convert.ToInt32(Console.ReadLine());
        Console.Write("Введите делитель: ");
        int b = Convert.ToInt32(Console.ReadLine());
        (int, int) c = Min_1(a, b);
        Console.WriteLine("Частное: " + c.Item1 + "\nОстаток: " + c.Item2);
    }
    static (int, int) Min_1(int divisible, int divider)
    {
        int sing_divisible = ((divisible >>> 31) ^ (divider >>> 31)) == 1 ? -1 : 1;
        bool sing_divider = ((divisible >>> 31) | (divider >>> 31)) == 1 ? true : false;
        divisible = divisible < 0 ? (divisible ^ -1) + 1 : divisible;
        divider = divider < 0 ? (divider ^ -1) + 1 : divider;
        int shift_divisible = 0, shift_divider = 0;
        int answer = 0;
        for (int i = divisible; i != 0; i >>>= 1) shift_divisible++;
        for (int i = divider; i != 0; i >>>= 1) shift_divider++;
        for (int i = divider << (shift_divisible - shift_divider); i >= divider; i >>>= 1)
        {   
            if (divisible >= i)
            {
                divisible -= i;
                answer = (answer << 1) + 1;
            }
            else answer <<= 1;
        }
        if (sing_divider) return (sing_divisible * (answer + 1), -1 * divisible + divider);
        else return (answer, divisible);
    }
}