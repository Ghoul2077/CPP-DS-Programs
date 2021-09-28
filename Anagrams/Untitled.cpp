#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Determines if given 2 strings are anagram in O(nlogn) time
 *             complexity and Q(1) space complexity.
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if strings are anagram, False otherwise.
 */
bool isAnagramNaive(string& str1, string& str2) {
   if (str1.size() != str2.size()) {
      cout << "False";
      return (false);
   }

   sort(str1.begin(), str1.end());
   sort(str2.begin(), str2.end());

   if (str1 == str2) {
      cout << "True";
      return (true);
   } else {
      cout << "False";
      return (false);
   }
}

/**
 * @brief      Determines if given 2 strings are anagram in O(n) time
 *             complexity and Q(128) space complexity. It does this by
 *             incrementing frequency when encountering character in string 1
 *             and decrementing counter when encountering character in string 2.
 *             The hypothesis is that if strings are anagram then the above
 *             method will yeild 0 for each value of count array.
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if strings are anagram, False otherwise.
 */
bool isAnagram(string& str1, string& str2) {
   if (str1.size() != str2.size()) {
      cout << "False";
      return (false);
   }

   int count[128] = { 0 };

   for (bigInt i = 0; i < str1.size(); i++) {
      int asciiVal1 = (int)str1[i];
      int asciiVal2 = (int)str2[i];
      count[asciiVal1]++;
      count[asciiVal2]--;
   }

   for (int i = 0; i < 128; i++) {
      if (count[i] != 0) {
         return (false);
      }
   }

   return (true);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str1, str2;
      getline(cin, str1);
      getline(cin, str2);
      isAnagram(str1, str2);
      cout << endl;
   }

   return (0);
}
