#include <iostream>
using namespace std;

int sumOfDigits(int num) {
   if (num < 10) {
      return(num);
   }
   return((num % 10) + sumOfDigits(num / 10));
}

int sumOfDigitsTailReccursion(int num, int sum = 0) {
   if (num < 10) {
      return(sum + num);
   }
   sum += num % 10;
   return(sumOfDigitsTailReccursion(num / 10, sum));
}

int main() {
   int sum = sumOfDigitsTailReccursion(443);

   cout << sum;
}
