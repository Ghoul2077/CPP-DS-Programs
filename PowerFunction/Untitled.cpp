#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;

/**
 * @brief      Find x^y for given x and y in O(n) time and Q(1) space.
 *
 * @param[in]  x     Base
 * @param[in]  y     Exponent
 *
 * @return     Values of x^y
 */
int powerNaive(int x, int y) {
   int res = 1;

   for (int i = 0; i < y; i++) {
      res *= x;
   }

   return res;
}

/**
 * @brief      Find x^y for given x and y in O(logn) time and Q(1) space using
 *             repetetive division.
 *
 * @param[in]  x     Base
 * @param[in]  y     Exponent
 *
 * @return     Values of x^y
 */
int power(int x, int y) {
   int res = 1;

   while(y > 0) {
      if(y & 1) {
         res *= x;
         y--;
      } else {
         x *= x;
         y /= 2;
      }
   }

   return res;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int x, y;
      cin >> x;
      cin >> y;
      cout << power(x, y);
      cout << endl;
   }

   return (0);
}
