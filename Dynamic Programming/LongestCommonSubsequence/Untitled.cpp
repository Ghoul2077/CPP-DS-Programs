#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Given 2 strings we need to find the longest common subsequence (
 *             elements of subsequence can occure with gap instead of being
 *             continuous like substrings). The idea is to understand that there
 *             are only 2 cases that can arise at any given point while
 *             traversing the strings from left to right i.e either the letter
 *             being considered in both the strings are equal or they are not.
 *             If they are equal then we can remove those letters from both the
 *             strings and then add 1 to the result and return. If they are not
 *             equal we go to 2 paths that is keep string 1 as it is and remove
 *             current letter from string 2 or keeps string 2 as it is and
 *             remove current letter from string 1, store both the results in
 *             variable and return the maximum from the 2. It's time complexity
 *             is O(2^N) and it's space complexity is O(N).
 *
 * @param[in]  str1  The string 1
 * @param[in]  str2  The string 2
 *
 * @return     Length of longest common subsequence
 */
int longestCommonSubsequenceNaive(string str1,
                                  string str2
                                  ) {
   if ((str1.size() == 0) || (str2.size() == 0)) {
      return (0);
   }

   if (str1[0] == str2[0]) {
      return (1 + longestCommonSubsequence2(str1.substr(1), str2.substr(1)));
   } else {
      int res2 = longestCommonSubsequence2(str1, str2.substr(1));
      int res3 = longestCommonSubsequence2(str1.substr(1),
                                           str2);

      return (max(res2, res3));
   }
}

int dp[1000][1000] = { -1 };

/**
 * @brief      Given 2 strings we need to find the longest common subsequence (
 *             elements of subsequence can occure with gap instead of being
 *             continuous like substrings). The idea is to use concept of
 *             dynamic programming to optimize reccursive apporach because of
 *             the subproblem's overlapping nature. Here we make a memoization
 *             table where we store the result of comparision of 2 substrings.
 *             It's time complexity is O(N) and it's space complexity is O(N).
 *
 * @param[in]  str1  The string 1
 * @param[in]  str2  The string 2
 *
 * @return     Length of longest common subsequence
 */
int longestCommonSubsequenceUsingDynamicProgramming(string str1,
                                                    string str2,
                                                    int    size1,
                                                    int    size2
                                                    ) {
   if ((size1 == 0) || (size2 == 0)) {
      dp[size1][size2] = 0;
      return (0);
   }

   if (dp[size1][size2] != -1) {
      return (dp[size1][size2]);
   }

   int ans;

   if (str1[size1 - 1] == str2[size2 - 1]) {
      ans = (1 + longestCommonSubsequence3(str1, str2, size1 - 1, size2 - 1));
   } else {
      ans = (max(longestCommonSubsequence3(str1, str2, size1 - 1, size2),
                 longestCommonSubsequence3(str1, str2, size1, size2 - 1)));
   }

   dp[size1][size2] = ans;

   return (ans);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str1, str2;
      getline(cin, str1);
      getline(cin, str2);
      fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1);
      cout << longestCommonSubsequenceUsingDynamicProgramming(str1,
                                                              str2,
                                                              str1.size(),
                                                              str2.size());
      cout << endl;
   }
   return (0);
}
