using System.Collections;
using System.Drawing;

namespace mini28;

public class HeshBlum<T>
{
     public int CountRequests { get; set; }
     public double ProbabilityError { get; set; }
     private BitArray _bitArray;
     private Convert heshConvert;
     private int[] keyHesh;
     
     public HeshBlum(int countRequests, double probabilityError, Convert convert){
          CountRequests = countRequests;
          ProbabilityError = probabilityError;
          heshConvert = convert;
          int bitArraySize = (int)Math.Ceiling(Math.Log(probabilityError, double.E)/ Math.Log(0.5f, double.E));
          keyHesh = new int[(int)Math.Ceiling(Math.Log(2, double.E) * bitArraySize)];
          _bitArray = new BitArray((bitArraySize *countRequests));
          Random r = new Random();
          for (int i = 0; i < keyHesh.Length; i++) {
               keyHesh[i] = r.Next(1, _bitArray.Length);
          }
     }

     public void insert(T value){
          foreach (var t in keyHesh) {
               _bitArray[(int)(heshConvert(value) % t)] = true;
          }
     }

     public bool lookup(T value){
          bool answer = true;
          foreach (var t in keyHesh) {
               if (_bitArray[(int)(heshConvert(value) % t)] == false) answer = false;
          }
          return answer;
     }
     
     public delegate long Convert(T value);
     
}