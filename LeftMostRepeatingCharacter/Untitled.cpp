#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Finds the first repeating character from left in a given string
 *             in O(string_len^2) time complexity and Q(1) space complexity
 *
 * @param[in]  str   The string
 *
 * @return     First repeating character if found any, empty string otherwise
 */
char leftMostRepeatingCharacterNaive(string& str) {
   for (bigInt i = 0; i < str.size(); i++) {
      for (bigInt j = i + 1; j < str.size(); j++) {
         if (str[i] == str[j]) {
            return (str[i]);
         }
      }
   }
   return (' ');
}

/**
 * @brief      Finds the first repeating character from left in a given string
 *             in O(string_len) time complexity and Q(1) space complexity by
 *             calculating frequency of each element and picking first one with
 *             frequency greater than 2. Here we use 2 loops.
 *
 * @param[in]  str   The string
 *
 * @return     First repeating character if found any, empty string otherwise
 */
char leftMostRepeatingCharacter(string &str) {
   int count[128] = { 0 };

   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];
      count[asciiVal]++;
   }

   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];

      if (count[asciiVal] > 1) {
         return (str[i]);
      }
   }

   return (' ');
}

/**
 * @brief      Finds the first repeating character from left in a given string
 *             in O(string_len) time complexity and Q(1) space complexity by
 *             storing the first occurance of every element and pciking the
 *             reccuring one with the least value of first occurance.
 *
 * @param[in]  str   The string
 *
 * @return     First repeating character if found any, empty string otherwise
 */
string leftMostRepeatingCharacterOptimized(string &str) {
   int firstOccurances[128];

   fill(firstOccurances, firstOccurances + 128, -1);

   string firstRepeatingChar      = " ";
   int    firstRepeatingCharIndex = INT_MAX;


   for (bigInt i = 0; i < str.size(); i++) {
      int asciiVal = (int)str[i];

      if (firstOccurances[asciiVal] == -1) {
         firstOccurances[asciiVal] = i;
      } else {
         if (firstOccurances[asciiVal] < firstRepeatingCharIndex) {
            firstRepeatingChar      = str[i];
            firstRepeatingCharIndex = firstOccurances[asciiVal];
         }
      }
   }

   return (firstRepeatingChar);
}

/**
 * @brief      Finds the first repeating character from left in a given string
 *             in O(string_len) time complexity and Q(1) space complexity by
 *             traversing the array from the right.
 *
 * @param[in]  str   The string
 *
 * @return     First repeating character if found any, empty string otherwise
 */
string leftMostRepeatingCharacterEfficient(string &str) {
   bool visited[128];

   fill(visited, visited + 128, false);

   string firstRepeatingChar = " ";

   for (int i = str.size() - 1; i >= 0; i--) {
      int asciiVal = (int)str[i];

      if (visited[asciiVal]) {
         firstRepeatingChar = str[i];
      } else {
         visited[asciiVal] = true;
      }
   }

   return (firstRepeatingChar);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      cout << leftMostRepeatingCharacterEfficient(str);
      cout << endl;
   }

   return (0);
}
