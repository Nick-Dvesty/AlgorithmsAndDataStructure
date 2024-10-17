using System.Collections;
using System.IO.Compression;
using LibGit2Sharp;

public class Mini_2
{
    public static void start(){
        for (int j = 0; j < 100; j++) {
            Random R = new Random();
            int b1 = R.Next(0, 10000);
            int b2 = R.Next(0, 10000);
            BitArray bit = new BitArray(new int[] {b1});
            BitArray bit2 = new BitArray(new int[] {b2});
            BitArray answer_bit = Min_2(bit, bit2);
            var answer = 0;
            for (int i = 0; i < answer_bit.Length; i++) {
                if (answer_bit[i]) answer += (int)Math.Pow(2,i);
            }
            if (answer != b1 * b2) Console.WriteLine($"Error:{b1} * {b2} != {answer}");
            else Console.WriteLine($"Complete: {b1} * {b2} == {answer}");
        }
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

    static BitArray Min_2(BitArray int_a, BitArray int_b){
        if (Less(int_a, 2) && Less(int_b, 2)) return new BitArray(new int[1]{Convert.ToInt32(int_a[0] && int_b[0])});
        else {
            BitArray max = Max(int_a, int_b);
            BitArray min = max == int_a ? int_b : int_a;
            var shift = max.Length;
            for (int i = 0; i < max.Length; i++) {
                if (max[i]) shift = i + 1;
            }
            if ((shift & 1) == 1) shift++;
            BitArray a = ShiftRight(max, (shift / 2));
            BitArray b = Sub(max, ShiftLeft(a, (shift / 2)));
            BitArray c = ShiftRight(min, (shift / 2));
            BitArray d = Sub(min, ShiftLeft(c, (shift / 2)));
            BitArray int1 = Min_2(a, c);
            BitArray int2 = Min_2(b, d);
            BitArray int3 = Min_2(Sum(a, b), Sum(c, d));
            int3 = Sub(Sub(int3, int2), int1);
            return Sum(Sum(ShiftLeft(int1, shift), ShiftLeft(int3, shift/2)), int2);
        }
    }
    static BitArray Sum(in BitArray var1, in BitArray var2){
        var bufer = false;
        var maxSize = var1.Length > var2.Length ? var1.Length : var2.Length;
        BitArray bitArray = new BitArray(maxSize);
        for (int i = 0; i < maxSize; i++) {
                bitArray[i] = var1[i] ^ var2[i] ^ bufer;
                bufer = (var1[i] & var2[i]) | (var1[i] & bufer) | (var2[i] & bufer);
        }
        return bitArray;
    } 
    static BitArray Sub( in BitArray var1, in BitArray var2){
        var bufer = false;
        var maxSize = var1.Length > var2.Length ? var1.Length : var2.Length;
        BitArray bitArray = new BitArray(maxSize);
        for (int i = 0; i < maxSize; i++) {
            bitArray[i] = var1[i] ^ var2[i] ^ bufer;
            bufer = (!var1[i] & var2[i]) | (!var1[i] & bufer) | (var2[i] & bufer);
        }
        return bitArray;
    }
    static bool Less(in BitArray array, in int number){
        for (int i = array.Length - 1; i != 0; i--) {
            if (array[i]) return false;
        }
        int arrayValue = 0;
        for (int i = 0; i < 32; i++)
        {
            if (array[i])
            {
                arrayValue += (int)Math.Pow(2, i);
            }
        }
        return arrayValue < number;
    }
    static BitArray Max( in BitArray arr1, in BitArray arr2){
        BitArray max, min;
        if (arr1.Length >= arr2.Length) {
            max = arr1;
            min = arr2;
        } 
        else {
            max = arr2;
            min = arr1;
        }
        for (int i = max.Length - 1; i >= 0; i--) {
            if (i > min.Length && max[i]) return max;
            if (i < min.Length && max[i] && !min[i]) return max;
            if (i < min.Length && !max[i] && min[i]) return min;
        }
        return max;
    }
    static BitArray ShiftRight( in BitArray arr, in int number){
        BitArray shBitArray = new BitArray(arr.Length);
        for (int i = 0; i < arr.Length; i++) {
            if (i + number < arr.Length) shBitArray[i] = arr[i + number];
            else shBitArray[i] = false;
        }
        return shBitArray;
    }
    static BitArray ShiftLeft( in BitArray arr, in int number){
        BitArray shBitArray = new BitArray(arr.Length);
        for (int i = arr.Length-1; i >= 0; i--) {
            if (i - number >= 0) shBitArray[i] = arr[i - number];
            else shBitArray[i] = false;
        }
        return shBitArray;
    }
    
}
