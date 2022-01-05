#include <bits/stdc++.h>
using namespace std;

int countDigit(int num) {
   int i, count = 0;

   while (num > 0) {
      num = num / 10;
      ++count;
   }
   return (count);
}

int countDigitReccursive(int num) {
   if (num == 0) {
      return (0);
   }
   return (1 + countDigitReccursive(int(num / 10)));
}

int countDigitLog(int num) {
   return (floor(log10(num) + 1));
}

int main() {
   int x;

   cout << "Enter Number : ";
   cin >> x;
   cout << countDigit(x) << endl;
   cout << countDigitReccursive(x) << endl;
   cout << countDigitLog(x);
}
