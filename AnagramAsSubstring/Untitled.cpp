#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool isAnagramModified(string& str1, string& str2, int startingIndex = 0) {
   if (str1.size() - startingIndex < str2.size()) {
      return (false);
   }
   int count[128] = { 0 };

   for (bigInt i = startingIndex; i < startingIndex + str2.size(); i++) {
      int asciiVal1 = (int)str1[i];
      int asciiVal2 = (int)str2[i - startingIndex];
      count[asciiVal1]++;
      count[asciiVal2]--;
   }

   for (bigInt i = 0; i < 128; i++) {
      if (count[i] != 0) {
         return (false);
      }
   }
   return (true);
}

/**
 * @brief      Finds anagram (any order of characters is possible) of a pattern
 *             as a substring in a given string in O(n^3) time complexity and
 *             Q(1) space complexity
 *
 * @param      str      The string
 * @param      pattern  The pattern
 *
 * @return     True if found, else False
 */
bool anagramSearchNaive(string& str, string& pattern) {
   for (bigInt i = 0; i <= str.size() - pattern.size(); i++) {
      bigInt j;

      for (j = 0; j < pattern.size(); j++) {
         bool isFound = false;

         for (bigInt k = i; k < i + pattern.size(); k++) {
            if (pattern[j] == str[k]) {
               isFound = true;
            }
         }

         if (!isFound) {
            break;
         }
      }

      if (j == pattern.size()) {
         return (true);
      }
   }
   return (false);
}

/**
 * @brief      Search for anagram of a given string as a substring of another
 *             string in O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      str      The string
 * @param      pattern  The pattern
 *
 * @return     True if found, False otherwise
 */
bool anagramSearchNaiveOptimized(string& str, string& pattern) {
   for (bigInt i = 0; i <= str.size() - pattern.size(); i++) {
      if (isAnagramModified(str, pattern, i)) {
         return (true);
      }
   }
   return (false);
}

/**
 * @brief      Search for anagram of a given string as a substring of another
 *             string in O(n) time complexity and Q(1) space complexity. We do
 *             this by using combination of count of characters in a
 *             hash and sliding window technique.
 *
 * @param      str      The string
 * @param      pattern  The pattern
 *
 * @return     True if found, False otherwise
 */
bool anagramSearch(string& str, string& pattern) {
   int countString[128]  = { 0 };
   int countPattern[128] = { 0 };

   for (bigInt i = 0; i < pattern.size(); i++) {
      int asciiVal1 = (int)str[i];
      int asciiVal2 = (int)pattern[i];
      countString[asciiVal1]++;
      countPattern[asciiVal2]++;
   }

   for (bigInt i = pattern.size(); i <= str.size() - pattern.size(); i++) {
      bool areEqual = true;

      for (int j = 0; j < 128; j++) {
         if (countString[i] != countPattern[i]) {
            areEqual = false;
            break;
         }
      }

      if (areEqual) {
         return (true);
      }

      int asciiVal1 = (int)str[i - pattern.size()];
      countString[asciiVal1]--;
      int asciiVal2 = (int)str[i];
      countString[asciiVal2]++;
   }

   return (false);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str, pattern;
      getline(cin, str);
      getline(cin, pattern);
      cout << anagramSearch(str, pattern);
      cout << endl;
   }

   return (0);
}
