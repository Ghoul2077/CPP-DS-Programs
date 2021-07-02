#include <iostream>
#include <algorithm>
using namespace std;

int lcmNaiveApproach(int num1, int num2) {
   int lcm = max(num1, num2);

   while (true) {
      if (lcm % num1 == 0 && lcm % num2 == 0) {
         break;
      }
      lcm++;
   }
   return(lcm);
}

int gcd(int num1, int num2) {
   if (num2 == 0) {
      return(num1);
   }else{
      return(gcd(num2, num1 % num2));
   }
}

int lcm(int num1, int num2) {
   // Time complexity is O(log(min(a, b))) which is complexity of euclid's algorithm to find gcd
   return((num1 * num2) / gcd(num1, num2));
}

int main() {
   int input1, input2;

   cout << "Enter Number 1 : ";
   cin >> input1;
   cout << "Enter Number 2 : ";
   cin >> input2;
   cout << "LCM is " << lcm(input1, input2);
}
