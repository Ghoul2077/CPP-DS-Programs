#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Creates an array to store sum of all values from 0 to each index
 *             in O(n) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Prefix sum array pointer
 */
int* prefixSumArray(int *arr, int size) {
   int *sumArray = new int[size];

   sumArray[0] = arr[0];

   for (int i = 1; i < size; i++) {
      sumArray[i] = sumArray[i - 1] + arr[i];
   }

   return (sumArray);
}

/**
 * @brief      Gets the sum from given start index to given stop index in O(1)
 *             assuming prefix sum array is precomputed and given.
 *
 * @param[in]  sumArray  The prefix sum array
 * @param[in]  size      The size
 * @param[in]  start     The start index
 * @param[in]  stop      The stop index
 *
 * @return     The sum of values from start to stop.
 */
int getSum(const int *sumArray, int size, int start, int stop) {
   int sum;

   if (start != 0) {
      sum = sumArray[stop] - sumArray[start - 1];
   } else {
      sum = sumArray[stop];
   }
   return (sum);
}

/**
 * @brief      Finds a center element in O(n) time given an array with
 *             precomputed prefix sum array.
 *             Center element is one whose sum of left elements and right
 *             elements is equal
 *
 * @param      sumArray  The sum array
 * @param[in]  size      The size
 *
 * @return     Index of center element of array if any otherwise -1
 */
int findCenterElement(int *sumArray, int size) {
   if (size == 1) {
      return (0);
   }
   int centerElementIndex = -1;

   for (int i = 1; i < size; i++) {
      if (sumArray[i - 1] == sumArray[size - 1] - sumArray[i]) {
         centerElementIndex = i;
      }
      break;
   }
   return (centerElementIndex);
}

int main() {
   int arr[]      = { 30, 5, 20, 7, 3 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   int *sumArray = prefixSumArray(arr, size);

   cout << findCenterElement(sumArray, size);
   return (0);
}
