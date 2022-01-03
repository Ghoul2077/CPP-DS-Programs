#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Determines if string 2 subsequence occurs in string 1 in O(n + m)
 *             time complexity and Q(1) space complexity.
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if subsequence exists, False otherwise.
 */
bool isSubsequenceIterative(const string& str1, const string& str2) {
   bigInt ptr1 = 0, ptr2 = 0;

   while (ptr1 < str1.size() && ptr2 < str2.size()) {
      if (str1[ptr1] == str2[ptr2]) {
         ptr1++;
         ptr2++;
      } else {
         ptr1++;
      }
   }

   if (ptr2 == str2.size()) {
      cout << "Found";
      return (true);
   } else {
      cout << "Not Found";
      return (false);
   }
}

/**
 * @brief      Determines if string 2 subsequence occurs in string 1 in O(n + m)
 *             time complexity and Q(n + m) space complexity. It uses reccursion
 *             and need more space and parameters than iterative method.
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if subsequence exists, False otherwise.
 */
bool isSubsequenceReccursive(const string& str1,
                             const string& str2,
                             const bigInt  size1,
                             const bigInt  size2) {
   if (size2 == 0) {
      cout << "Found";
      return (true);
   } else if (size1 == 0) {
      cout << "Not Found";
      return (false);
   }

   if (str2[size2 - 1] == str1[size1 - 1]) {
      return (isSubsequenceReccursive(str1, str2, size1 - 1, size2 - 1));
   } else {
      return (isSubsequenceReccursive(str1, str2, size1 - 1, size2));
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str1, str2;
      getline(cin, str1);
      getline(cin, str2);
      isSubsequenceReccursive(str1, str2, str1.size(), str2.size());
      cout << endl;
   }

   return (0);
}
