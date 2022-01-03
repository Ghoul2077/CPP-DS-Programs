#include <bits/stdc++.h>
using namespace std;

int factorial(int num) {
   int result = 1;

   while (num != 1) {
      result = result * num--;
   }
   return (result);
}

int trailingZeroesNaiveApproach(int num) {
   // Time complexity is Q(n) and auxillary space is Q(1)
   long int count = 0, fact = factorial(num);

   while ((fact % 10) == 0) {
      count++;
      num /= 10;
   }
   return (count);
}

int trailingZeroes(int num) {
   // Here we are exploiting the property of factorials that is in prime factorization of a factorial the number of 5 will always be less than number of 2
   // Hence pair will be equal to number of 5 in given factorial factorization
   // Complexity is Q(log5(n)) and auxillary space is Q(1)
   int result = 0;

   for (int i = 5; i <= num; i = i * 5) {
      result = result + num / i;
   }
   return (result);
}

int main() {
   int input;

   cout << "Enter Number : ";
   cin >> input;
   cout << trailingZeroes(input);
}
