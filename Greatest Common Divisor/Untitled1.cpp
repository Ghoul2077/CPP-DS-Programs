#include <iostream>
#include <algorithm>
using namespace std;

int gcdNaiveApproach(int num1, int num2) {
   // Time complexity is O(min(a, b))
   int gcd = min(num1, num2);

   while (gcd > 0) {
      if (num1 % gcd == 0 && num2 % gcd == 0) {
         break;
      }
      gcd--;
   }
   return(gcd);
}

int gcdEuclidApproach(int num1, int num2) {
   // Euclid's Algorithm
   while (num1 != num2) {
      if (num1 > num2) {
         num1 -= num2;
      }else  {
         num2 -= num1;
      }
   }
   return(num1);
}

int gcdEuclidApproachOptimized(int num1, int num2) {
   // Euclid's Algorithm Optimized
   if (num2 == 0) {
      return(num1);
   }else{
      return(gcdEuclidApproachOptimized(num2, num1 % num2));
   }
}

int main() {
   int input1, input2;

   cout << "Enter Number 1 : ";
   cin >> input1;
   cout << "Enter Number 2 : ";
   cin >> input2;
   cout << "GCD is " << gcdEuclidApproachOptimized(input1, input2);
}
