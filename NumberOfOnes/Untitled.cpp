#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief      Counts the number of ones of a sorted boolean array in O(n) time 
 *             complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Number of ones.
 */
int countNumberOfOnesNaive(int *arr, int size) {
   int count = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] == 1) {
         count++;
      }
   }
   return(count);
}

/**
 * @brief      Counts the number of ones of a sorted boolean array in O(logn) 
 *             time complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Number of ones.
 */
int countNumberOfOnes(int *arr, int size) {
   int start = 0, stop = size - 1;

   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] == 0) {
         start = mid + 1;
      } else {
         if (mid == 0 || arr[mid - 1] == 0) {
            return(size - mid);
         } else {
            stop = mid - 1;
         }
      }
   }

   return(0);
}

int main() {
   int       arr[] = { 0, 0, 0, 1, 1, 1, 1, 1 };
   const int size  = sizeof(arr) / sizeof(arr[0]);

   cout << countNumberOfOnes(arr, size);
   return(0);
}
