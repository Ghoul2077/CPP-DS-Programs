#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNaiveApproach(int num) {
   // Time complexity is O(n)
   if (num == 1) {
      return(false);
   }
   int count = 0;

   for (int i = 2; i < num; i++) {
      if (num % i == 0) {
         count++;
      }
   }
   return(count == 0 ? true : false);
}

bool isPrime(int num) {
   // Time complexity is O(n^1/2)
   if (num == 1) {
      return(false);
   }

   for (int i = 2; i <= pow(num, 0.5); i++) {
      if (num % i == 0) {
         return(false);
      }
   }
   return(true);
}

bool isPrimeEfficient(int num) {
   // Time complexity is O(n^1/2)
   if (num == 1) {
      return(false);
   }
   if (num == 2 || num == 3) {
      return(true);
   }
   if (num % 2 == 0 || num % 3 == 0) {
      return(false);
   }
   for (int i = 5; i <= pow(num, 0.5); i += 6) {
      if (num % i == 0 || num % (i + 2) == 0) {
         return(false);
      }
   }
   return(true);
}

int main() {
   int input;

   cout << "Enter Number : ";
   cin >> input;
   cout << (isPrimeEfficient(input) ? "It is prime number" : "Not a prime number");
}
