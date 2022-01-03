#include <bits/stdc++.h>
using namespace std;

int reverseNum(int num) {
   int reversedNum = 0;

   while (num != 0) {
      reversedNum = reversedNum * 10 + (num % 10);
      num         = num / 10;
   }

   return (reversedNum);
}

bool isPalindrome(int num) {
   int i, digits = reverseNum(num);

   if (num == reverseNum(num)) {
      return (true);
   } else {
      return (false);
   }
}

int main() {
   // Time Complexity is Q(d) where d is the number of digits
   int num;

   cout << "Enter a number : ";
   cin >> num;
   cout << (isPalindrome(num) ? "Palindrome" : "Not a Palindrome");
}
