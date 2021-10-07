#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds the longest substring size which has all distinct
 *             characters in O(n^3) time complexity and Q(n) space complexity.
 *
 * @param      str   The string
 *
 * @return     Substring with distinct characters
 */
int longestSubstringWithDistinctCharactersNaive(string& str) {
   string res = "";

   for (bigInt i = 0; i < str.size(); i++) {
      for (bigInt j = i; j < str.size(); j++) {
         bigInt substringSize = j - i + 1;
         unordered_set<int> distinctElements(str.begin() + i,
                                             str.begin() + j + 1);

         if ((distinctElements.size() == substringSize) &&
             (res.size() < substringSize)) {
            res = str.substr(i, j + 1);
         }
      }
   }

   return (res.size());
}

/**
 * @brief      Finds the longest substring size which has all distinct
 *             characters in O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      str   The string
 *
 * @return     Substring with distinct characters
 */
int longestSubstringWithDistinctCharactersNaiveOptimized(string& str) {
   bigInt res = 0;

   for (bigInt i = 0; i < str.size(); i++) {
      vector<bool> isVisited(128, false);

      for (bigInt j = i; j < str.size(); j++) {
         int asciiVal = (int)str[j];

         if (isVisited[asciiVal] == true) {
            break;
         } else {
            res                 = max(res, j - i + 1);
            isVisited[asciiVal] = true;
         }
      }
   }

   return (res);
}

/**
 * @brief      Finds the longest substring size which has all distinct
 *             characters in O(n) time complexity and Q(128) space complexity.
 *
 * @param      str   The string
 *
 * @return     Substring with distinct characters
 */
int longestSubstringWithDistinctCharacters(string& str) {
   int count[128] = { 0 };
   bigInt start = 0, end = 0;
   bigInt maxSizeOfSubstring = 0;

   while (end < str.size()) {
      int asciiVal = (int)str[end];

      if (count[asciiVal] != 0) {
         maxSizeOfSubstring = max(end - start, maxSizeOfSubstring);
         start              = end;
         fill(count, count + 128, 0);
      }

      count[asciiVal]++;
      end++;
   }

   maxSizeOfSubstring = max(end - start, maxSizeOfSubstring);

   return (maxSizeOfSubstring);
}

/**
 * @brief      Finds the longest substring size which has all distinct
 *             characters in O(n) time complexity and Q(128) space complexity.
 *             It is better than previous apporach as it uses only one for loop
 *             and no further looping inside it.
 *
 * @param      str   The string
 *
 * @return     Substring with distinct characters
 */
int longestSubstringWithDistinctCharactersOptimized(string& str) {
   int prevDistinctSubstringLengths[128] = { -1 };
   int maxLen = 0, prev = 0;
   bigInt i = 0;

   for (bigInt j = 0; j < str.size(); j++) {
      int asciiVal = (int)str[j];
      prev = max(prev, prevDistinctSubstringLengths[asciiVal] + 1);
      int currLen = j - i + 1;
      maxLen                                 = max(maxLen, currLen);
      prevDistinctSubstringLengths[asciiVal] = j;
   }

   return (maxLen);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      cout << longestSubstringWithDistinctCharactersOptimized(str);
      cout << endl;
   }

   return (0);
}
