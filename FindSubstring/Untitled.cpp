#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds the index starting which a given pattern occurs in a string
 *             in O((n - m + 1) * m) time complexity and Q(1) space complexity
 *
 * @param      str      The string
 * @param      pattern  The pattern
 */
void patternSearchingNaive(string& str, string& pattern) {
   for (bigInt i = 0; i <= str.size() - pattern.size(); i++) {
      bool isPatternPresent = true;

      for (bigInt j = i; j < i + pattern.size(); j++) {
         if (str[j] != pattern[j - i]) {
            isPatternPresent = false;
            break;
         }
      }

      if (isPatternPresent) {
         cout << i << ", ";
      }
   }
}

/**
 * @brief      Finds the index starting which a given pattern occurs in a string
 *             in O(n) time complexity and Q(1) space complexity given that
 *             pattern we are searching consists of distint characters.
 *
 * @param      str      The string
 * @param      pattern  The pattern
 */
void patternSearchingNaiveOptimized(string& str, string& pattern) {
   for (bigInt i = 0; i <= str.size() - pattern.size();) {
      bigInt j;

      for (j = 0; j < pattern.size(); j++) {
         if (str[i + j] != pattern[j]) {
            break;
         }
      }

      if (j == pattern.size()) {
         cout << i << ", ";
      }

      if (j == 0) {
         i++;
      } else {
         i = i + j;
      }
   }
}

/**
 * @brief      Find the given substring in given string in O(mn) time complexity
 *             using Rabin Karp's method of rolling hash where we use weighted
 *             hashing to calculate hash. It's space complexity is Q(1). It is
 *             better than naive approach because we do less comparisions in
 *             general than in naive solution.
 *
 * @param      str      The string
 * @param      pattern  The pattern
 */
void subStringUsingRabinKarp(string& str, string& pattern) {
   int rollingHash = 0, patternHash = 0;
   int weight = 2, patternMaxWeight = 1;

   for (bigInt i = 1; i < pattern.size(); i++) {
      patternMaxWeight = (patternMaxWeight * weight) % mod;
   }

   for (bigInt i = 0; i < pattern.size(); i++) {
      patternHash = (patternHash * weight + pattern[i]) % mod;
      rollingHash = (rollingHash * weight + str[i]) % mod;
   }

   for (bigInt i = 0; i <= str.size() - pattern.size(); i++) {
      if (patternHash == rollingHash) {
         bool isEqual = true;

         for (bigInt j = 0; j < pattern.size(); j++) {
            if (str[i + j] != pattern[j]) {
               isEqual = false;
               break;
            }
         }

         if (isEqual) {
            cout << i << ", ";
         }
      }

      if (i < (str.size() - pattern.size())) {
         rollingHash =
            ((weight * (rollingHash - str[i] * patternMaxWeight)) +
             str[i + pattern.size()]) % mod;

         if (rollingHash < 0) {
            rollingHash += mod;
         }
      }
   }
}

// TODO: To be done after LPS Array Problem
void knuthMorisPrattAlgorithmForSubstring(string &str, string &pattern) {

}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str, pattern;
      getline(cin, str);
      getline(cin, pattern);
      knuthMorisPrattAlgorithmForSubstring(str, pattern);
      cout << endl;
   }

   return (0);
}
