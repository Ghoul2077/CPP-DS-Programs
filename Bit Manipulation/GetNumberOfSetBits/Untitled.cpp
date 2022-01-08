#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Gets the number of set bits in binary representation of a given
 *             number in base 10. It's time complexity is the number of bit used
 *             by cpu to represent an integer. Eg:- 32 bits then time complexity
 *             is O(32).
 *
 * @param[in]  num   The number in base 10
 *
 * @return     The number of set bits.
 */
int getNumberOfSetBits(int num) {
   int count = 0;

   while (num != 0) {
      if (num & 1) {
         count++;
      }
      num >>= 1;
   }
   return (count);
}

/**
 * @brief      Finds the number of set bits in binary representation of a given
 *             number in base 10. It's time complexity is O(number of set bits)
 *             and how it does it is by continuously performing and of num with
 *             num - 1 which unsets the right most set bit. This goes on until
 *             all the bits of the number are unset i.e it becomes 0.
 *
 * @param[in]  num   The number in base 10
 *
 * @return     Number of set bits
 */
int brianAndKerninghamAlgorithm(int num) {
   int count = 0;

   while (num != 0) {
      num = num & (num - 1);
      count++;
   }
   return (count);
}

int* createlookupTable() {
   int *table = new int[256];

   table[0] = 0;

   for (int i = 1; i < 256; i++) {
      table[i] = (i & 1) + table[i / 2];
   }
   return (table);
}

/**
 * @brief      Finds the number of set bits in the binary representation of a
 *             given number in base 10. It's time complexity is O(1) and how it
 *             does that is by some preprocessing and creating a lookup table
 *             of the number of set bits of each number from 0 to 255. Now by
 *             dividing our original 32 bit number to 4 chunks of 8 bits each
 *             ranging from 0 to 255 we add the number of set bits in each of
 *             this chunk by looking up in the lookup table and get the answer.
 *
 * @param[in]  num   The number in base 10
 *
 * @return     The number of set bits
 */
int lookUpTableMethod(int num) {
   int  count       = 0;
   int  mask        = 255;
   int *lookupTable = createlookupTable();

   for (int i = 0; i < 4; i++) {
      count += lookupTable[num & mask];
      num  >>= 8;
   }
   return (count);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int num;
      cin >> num;
      cout << lookUpTableMethod(num);
      cout << endl;
   }
   return (0);
}
