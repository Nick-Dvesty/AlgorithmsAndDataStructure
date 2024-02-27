using System;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    internal class Program
    {
        public static void Main(string[] args){
            string[] test = { "hello","aelli","aella" ,"aello" };
            string[] ans = countingSort(test);
            foreach (var VARIABLE in ans)
            {
                Console.WriteLine(VARIABLE);
            }
        }
        
        public static string[] countingSort(string[] array){
            int[] list = new int[128];
            for (int i = 0; i < array[0].Length; i++){
                list = new int[128];
                string[] ansArray = new string[array.Length];
                int index = array[0].Length - i - 1;
                for (int j = 0; j < array.Length; j++){
                    list[array[j][index]]++;
                }
                for (int j = 1; j < list.Length; j++){
                    list[j] += list[j - 1];
                }
                for (int j = array.Length - 1; j >= 0; j--){
                    ansArray[list[array[j][index]] - 1] = array[j];
                    list[array[j][index]]--;
                }
                array = ansArray;
            }
            return array;
        }
        
    }
}