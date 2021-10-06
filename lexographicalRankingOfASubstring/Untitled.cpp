#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int bigInt;
#define mod 1000000007;

int factorial(int num) {
   if (num <= 1) {
      return (1);
   } else {
      return (num * factorial(num - 1));
   }
}

/**
 * @brief      Finds the lexographic rank of a given string between all its
 *             permutations in O(n*128) time by keeping count of elements smaller
 *             than each element using count array. After this we apply simple
 *             permutation formula for getting our answer. Time complexity is
 *             Q(128);
 *
 * @param      str   The string
 *
 * @return     { description_of_the_return_value }
 */
int lexographicRankOfString(string& str) {
   int count[128]   = { 0 };
   int maxFactorial = factorial(str.size());
   int res          = 1;

   for (bigInt i = 0; i < str.size(); ++i) {
      int asciiVal = (int)str[i];
      count[asciiVal]++;
   }

   for (bigInt i = 1; i < 128; i++) {
      count[i] += count[i - 1];
   }

   for (bigInt i = 0; i < str.size(); i++) {
      maxFactorial = maxFactorial / (str.size() - i);
      int asciiVal = (int)str[i];
      res = res + count[asciiVal - 1] * maxFactorial;

      for (bigInt j = asciiVal; j < 128; j++) {
         count[j]--;
      }
   }

   return (res);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str, pattern;
      getline(cin, str);
      cout << lexographicRankOfString(str);
      cout << endl;
   }

   return (0);
}
