#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

int countSetBits(int num) {
   int count = 0;

   while (num > 0) {
      num &= (num - 1);
      count++;
   }
   return (count);
}

/**
 * @brief      Determines whether the specified number is power of 2. It's time
 *             time complexity is O(logn).
 *
 * @param[in]  num   The number in base 10
 *
 * @return     True if the specified number is power of 2, False otherwise.
 */
bool isPowerOf2Naive(int num) {
   if (num == 0) {
      return (false);
   }

   while (num != 1) {
      if (num % 2 != 0) {
         return (false);
      }
      num /= 2;
   }
   return (true);
}

/**
 * @brief      Determines whether the specified number is power of 2. It's time
 *             time complexity is O(1). The idea behind this method is to use
 *             brian kerningham algorithm to get number of set bits, if it is
 *             equal to one then our answer is that the number is power of 2
 *             otherwise false.
 *
 * @param[in]  num   The number in base 10
 *
 * @return     True if the specified number is power of 2, False otherwise.
 */
bool isPowerOf2(int num) {
   int countOfSetBits = countSetBits(num);

   return (countOfSetBits == 1);
}

/**
 * @brief      Determines whether the specified number is power of 2. It's time
 *             time complexity is O(1). The idea behind this method is to
 *             perform and of input number with it predecessor which unsets it's
 *             rightmost bit and for numbers which are power of 2 it is the only
 *             bit present so after doing this the result should be 0 for those
 *             numbers, based on which we return true or false.
 *
 *
 * @param[in]  num   The number in base 10
 *
 * @return     True if the specified number is power of 2, False otherwise.
 */
bool isPowerOf2Efficient(int num) {
   if (num == 0) {
      return (false);
   }
   return ((num & num - 1) == 0);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      cout << (isPowerOf2Efficient(num) ? "Yes" : "No");
      cout << endl;
   }
   return (0);
}
