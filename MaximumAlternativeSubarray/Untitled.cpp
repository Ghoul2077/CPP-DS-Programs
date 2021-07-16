#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief      Find maximum length of even odd alternative subarray using
 *             Kaden's algorithm in O(n) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum length of alternating subarray
 */
int maximumLengthEvenOddSubarray(int *arr, int size) {
   int count = 0;
   // Represents whether next element is odd or even
   int flag  = arr[0] % 2;

   // Loop through array comparing whether curr element is equal to assumed flag
   for (int i = 0; i < size; i++) {
      if (arr[i] % 2 == flag) {
         count++;
         flag = flag == 0 ? 1 : 0;
      } else {
         count = 1;
         flag  = arr[i] % 2 == 0 ? 1 : 0;
         continue;
      }
   }
   return(count);
}

int main() {
   int       arr[] = { 7, 10, 13, 14 };
   const int size  = sizeof(arr) / sizeof(arr[0]);

   cout << maximumLengthEvenOddSubarray(arr, size);
   return(0);
}
