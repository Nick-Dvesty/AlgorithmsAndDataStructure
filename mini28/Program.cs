// See https://aka.ms/new-console-template for more information

using mini28;

Console.WriteLine("Eenter the required error probability: ");
double probabilityError = Convert.ToDouble(Console.ReadLine());
Console.WriteLine("Eenter the required error probability: ");
int countRequests = Convert.ToInt32(Console.ReadLine());
HeshBlum<long> heshBlum= new HeshBlum<long>(countRequests, probabilityError, (value => value));

while (true) {
     Console.WriteLine("Enter comand");
     string comand = Console.ReadLine();
     Console.WriteLine("Enter IP");
     string IP = Console.ReadLine();
     if (comand == "insert") {
          heshBlum.insert(convertIP(IP));
          Console.WriteLine("IP has been added successfully");
     }
     else if (comand == "lookup") {
           Console.WriteLine(heshBlum.lookup(convertIP(IP)));
     }
}

long convertIP(string IP){
     long answer = 0;
     for (int i = 0; i < IP.Length; i++) {
          if (IP[i] != '.') {
               answer *= 10;
               answer += Convert.ToInt64(IP[i]);
          }
     }
     return answer;
}