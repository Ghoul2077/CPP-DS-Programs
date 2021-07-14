#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

int max(int num1, int num2) {
   return(num1 > num2 ? num1 : num2);
}

/**
 * @brief      Finds maximum sum that subarray has in O(n^2) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum sum of subarray
 */
int maximumSumSubarrayNaive(int *arr, int size) {
   int maxSum = 0;

   for (int i = 0; i < size; i++) {
      int currSum = 0;
      for (int j = i; j < size; j++) {
         currSum += arr[j];
         if (currSum > maxSum) {
            maxSum = currSum;
         }
      }
   }
   return(maxSum);
}

/**
 * @brief      Finds maximum sum that subarray has in O(n) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum sum of subarray
 */
int maximumSumSubarray(int *arr, int size) {
   int res    = arr[0];
   int maxSum = arr[0];

   for (int i = 1; i < size; i++) {
      maxSum = max(maxSum + arr[i], arr[i]);
      res    = max(res, maxSum);
   }

   return(res);
}

int main() {
   int       arr[] = { 2, 3, -8, 7, -1, 2, 3 };
   const int size  = sizeof(arr) / sizeof(arr[0]);

   cout << maximumSumSubarray(arr, size);
   return(0);
}
