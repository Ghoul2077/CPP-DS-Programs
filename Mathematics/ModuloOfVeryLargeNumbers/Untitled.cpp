#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds a modulo of given number with k. The trick is that the
 *             number is given as string and will be way bigger than 10^9 so we
 *             need to find an efficient way to solve this problem. For this we
 *             have used rolling remainder trick which says that if we know
 *             remainder of previous digit to left then we can calculate next
 *             remainder by doing (prevRemainder * 10 + newDigit) % k hence
 *             bringing time complexity down to O(n).
 *
 * @param      str   The string
 * @param[in]  k     The number to get modulo by
 *
 * @return     Remainder
 */
int findModuloK(string& str, int k) {
   if (k == 0) {
      return (-1);
   }

   int last_remainder = 0;

   for (bigInt i = 0; i < str.size(); i++) {
      int currNum = stoi(str.substr(i, 1));
      last_remainder = (last_remainder * 10 + currNum) % k;
   }

   return (last_remainder);
}

int main() {
   string str = "987688594028123102937589768503827491";
   int    k   = 11;

   cout << findModuloK(str, k);
   return (0);
}
