#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Gets the power set of the given string. This method using
 *             reccursion and it's time complexity is O(n) and it's space
 *             complexity is O(2^n).
 *
 * @param[in]  str     The string
 * @param[in]  subset  The subset
 * @param[in]  level   The reccursion depth / Index to consider
 */
void getPowerSetReccursive(string str, string subset = "", int level = 0) {
   if (str.size() == level) {
      cout << subset << " ";
      return;
   }
   getPowerSetReccursive(str, subset,              level + 1);
   getPowerSetReccursive(str, subset + str[level], level + 1);
}

/**
 * @brief      Gets the power set of the given string. This method using
 *             iterative method and bit manipulation. As we know that there are
 *             2^n subsets in a power set and we can see that binary
 *             representation is sort of resembling our subsets where 0 are the
 *             elements not picked for current subset and 1 representing the
 *             elements picked. So building upon that method we iterate from
 *             0 to 2^n - 1 and considering binary representation of each number
 *             in this range we convert that representation to our string by
 *             seeing at which places do we have 1s. It's time complexity is
 *             O(2^n)
 *
 * @param[in]  str     The string
 * @param[in]  subset  The subset
 * @param[in]  level   The reccursion depth / Index to consider
 */
void getPowerSetIterative(string str) {
   int sizeOfPowerSet = pow(2, str.size());

   for (int i = 0; i < sizeOfPowerSet; i++) {
      string currSubset = "";

      for (int j = 0; j < str.size(); j++) {
         if ((i >> j) & 1 == 1) {
            currSubset += str[j];
         }
      }
      cout << currSubset << " ";
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      getPowerSet(str);
      cout << endl;
   }
   return (0);
}
