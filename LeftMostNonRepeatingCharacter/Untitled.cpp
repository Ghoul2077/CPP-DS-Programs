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
char leftMostNonRepeatingCharacterNaive(string& str) {
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
 *             by filling array of 128 values with -1 (indicating not yet 
 *             encountered) and then traversing the string storing index value
 *             instead of -1 for first occurance otherwise -2 if already
 *             encountered. Now we just have to find the minimum of first
 *             occurances index values in the array & we get our answer.
 *
 * @param[in]  str   The string
 *
 * @return     First non repeating character if any, otherwise return " ".
 */
char leftMostNonRepeatingCharacterEfficient1(string& str) {
   int firstInstances[128], asiiValOfFirstNonRepeatingChar = INT_MAX;

   fill(firstInstances, firstInstances + 128, -1);

   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];

      if (firstInstances[asciiVal] == -1) {
         firstInstances[asciiVal] = i;
      } else {
         firstInstances[asciiVal] = -2;
      }
   }

   for (int i = 0; i < 128; i++) {
      if (firstInstances[i] >= 0) {
         asiiValOfFirstNonRepeatingChar = min(asiiValOfFirstNonRepeatingChar,
                                              firstInstances[i]);
      }
   }

   if (asiiValOfFirstNonRepeatingChar != INT_MAX) {
      return (str[asiiValOfFirstNonRepeatingChar]);
   } else {
      return (' ');
   }
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
char leftMostNonRepeatingCharacterEfficient2(string& str) {
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
      cout << leftMostNonRepeatingCharacterEfficient1(str);
      cout << endl;
   }

   return (0);
}
