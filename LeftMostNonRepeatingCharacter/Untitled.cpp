#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Finds the first non repeating character in a given string in
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param[in]  str   The string
 *
 * @return     First non repeating character if any, otherwise return " ".
 */
char leftMostNonRepeatingCharacterNaive(string &str) {
   for (bigInt i = 0; i < str.size(); i++) {
      bool isRepeating = false;

      for (bigInt j = i + 1; j < str.size(); j++) {
         if (str[i] == str[j]) {
            isRepeating = true;
         }
      }

      if (!isRepeating) {
         return (str[i]);
      }
   }
   return (' ');
}

/**
 * @brief      Finds the first non repeating character in a given string in
 *             O(n) time complexity and Q(128) space complexity. It does this
 *             by traversing the array from the right and talking an account of
 *             all the values that have been visited in a boolean array of size
 *             128.
 *
 * @param[in]  str   The string
 *
 * @return     First non repeating character if any, otherwise return " ".
 */
string leftMostNonRepeatingCharacterEfficient1(string &str) {
   bool isVisited[128];

   fill(isVisited, isVisited + 128, false);

   string firstNonRepeatingChar = " ";

   for (int i = str.size() - 1; i >= 0; i--) {
      int asciiVal = (int)str[i];

      if (!isVisited[asciiVal]) {
         firstNonRepeatingChar = str[i];
         isVisited[asciiVal]   = true;
      }
   }

   return (firstNonRepeatingChar);
}

/**
 * @brief      Finds the first non repeating character in a given string in
 *             O(n) time complexity and Q(128) space complexity. It does this
 *             by storing the frequency count of all characters and then finding
 *             the first occuring character with 1 frequency. Contrary to
 *             efficient approach 1 it uses 2 for loops so in comparision
 *             approach 1 is still better than 2nd one.
 *
 * @param[in]  str   The string
 *
 * @return     First non repeating character if any, otherwise return " ".
 */
char leftMostNonRepeatingCharacterEfficient2(string &str) {
   int count[128] = { 0 };

   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];
      count[asciiVal]++;
   }

   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];
      if (count[asciiVal] == 1) {
         return (str[i]);
      }
   }
   return (' ');
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      cout << leftMostNonRepeatingCharacterEfficient2(str);
      cout << endl;
   }

   return (0);
}
