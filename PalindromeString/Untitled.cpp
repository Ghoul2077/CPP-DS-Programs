#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Determines whether the specified string is palindrome in Q(n)
 *             time complexity and Q(n) space complexity.
 *
 * @param      str   The string
 *
 * @return     True if the specified string is palindrome , False otherwise.
 */
bool isPalindromeNaive(string& str) {
   string reverseString = str;

   reverse(reverseString.begin(), reverseString.end());

   if (str == reverseString) {
      cout << "True" << endl;
      return (true);
   } else {
      cout << "False" << endl;
      return (false);
   }
}

/**
 * @brief      Determines whether the specified string is palindrome in O(n)
 *             time complexity and Q(1) space complexity.
 *
 * @param      str   The string
 *
 * @return     True if the specified string is palindrome, False otherwise.
 */
bool isPalindrome(string& str) {
   for (bigInt i = 0; i < str.size() / 2; i++) {
      if (str[i] != str[str.size() - i - 1]) {
         cout << "False" << endl;
         return (false);
      }
   }
   cout << "True" << endl;
   return (true);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      isPalindrome(str);
   }

   return (0);
}
