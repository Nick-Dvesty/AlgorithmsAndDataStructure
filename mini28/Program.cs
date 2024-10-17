// See https://aka.ms/new-console-template for more information

using mini28;

test(0.4f, 1000,500);
return;
Console.Write("Enter the required error probability: ");
double probabilityError = Convert.ToDouble(Console.ReadLine());
Console.Write("Enter count words: ");
int countRequests = Convert.ToInt32(Console.ReadLine());
HeshBlum<long> heshBlum= new HeshBlum<long>(countRequests,probabilityError, (value => value));

while (true) {
     Console.Write("Enter comand: ");
     string comand = Console.ReadLine();
     if (comand is "insert" or "lookup") {
          Console.Write("Enter IP: ");
          string IP = Console.ReadLine();
          if (comand == "insert") {
               heshBlum.insert(convertIP(IP));
               Console.WriteLine("IP has been added successfully");
          }
          else if (comand == "lookup") {
               Console.WriteLine(heshBlum.lookup(convertIP(IP)));
          }
     }
}

long convertIP(string IP){
     long answer = 0;
     for (int i = 0; i < IP.Length; i++) {
          if (IP[i] != '.') {
               answer *= 10;
               answer += IP[i] - 48;
          }
     }
     return answer;
}


void test(float cof, int count, int useCount){
     HeshBlum<long> heshBlum= new HeshBlum<long>(count, cof, (value => value));
     int fAlarm = 0, tAlarm = 0;
     int[] Ips = new int[useCount];
     Random r = new Random();
     for (int i = 0; i < Ips.Length; i++) {
          Ips[i] = r.Next(100000000,200000000);
          heshBlum.insert(Ips[i]);
     }
     for (int i = 100000000; i < 200000000; i++) {
          if (heshBlum.lookup(i)) {
               for (int j = 0; j < Ips.Length; j++) {
                    if (Ips[j] == i) tAlarm++;
               }
               fAlarm++;
          }
          if (i % 100000 == 0) {
               Console.WriteLine($"true: {tAlarm} false: {(float)(fAlarm - tAlarm)/ (i -100000000)}");
          }
     }
     fAlarm -= tAlarm;
}