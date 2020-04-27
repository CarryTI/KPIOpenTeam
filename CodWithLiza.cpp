#include <iostream>
using namespace std;

void myFunc (int n)
{
  int Liza[n];
  Liza[0] = 0;
  Liza[1] = 1;

  for (int i = 0; i < n; i++) {
    if(i > 1)
       Liza[i] = Liza[i-1] + Liza[i-2];
   cout << Liza[i] << " ";
  }
}

 int main(int argc, char const *argv[])                              //МЕЙН
 {
   int n;

   cout << "Print the count of fibanachis number: ";
   cin >> n;

   myFunc(n);
   cout << "\n";
   myFunc(n + 5);
    cout << "\n";
   myFunc(n + 10);

   return 0;
 }
