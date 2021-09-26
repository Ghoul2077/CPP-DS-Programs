#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

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
 *             complexity and O(n) space complexity.
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

   unordered_set<char> alphabetSet1(str1.begin(), str1.end());
   unordered_set<char> alphabetSet2(str2.begin(), str2.end());

   if(alphabetSet1 == alphabetSet2) {
      cout << "True";
      return (true);
   } else {
      cout << "False";
      return (false);
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
      isAnagram(str1, str2);
      cout << endl;
   }

   return (0);
}
