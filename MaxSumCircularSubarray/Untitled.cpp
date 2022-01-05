#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int *arr, int size) {
   int res    = arr[0];
   int maxSum = arr[0];

   for (int i = 1; i < size; i++) {
      maxSum = max(maxSum + arr[i], arr[i]);
      res    = max(res, maxSum);
   }

   return (res);
}

/**
 * @brief      Find maximum circular subarray sum in O(n^2) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum sum of circular subarray
 */
int maximumSumCircularSubarrayNaive(int *arr, int size) {
   int maxSum = INT_MIN;

   for (int i = 0; i < size; i++) {
      int newSum = arr[i];

      for (int j = i + 1; j < i + size; j++) {
         int currIndex = j % size;
         newSum = max(arr[currIndex] + newSum, newSum);
         maxSum = max(newSum, maxSum);
      }
   }
   return (maxSum);
}

/**
 * @brief      Find maximum circular subarray sum in O(n) time complexity
 *             by finding normal max sum using kadence algorithm then finding
 *             max sum for circular array by subtracting minimum sum from total
 *             sum of array
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum sum of circular subarray
 */
int maximumSumCircularSubarray(int *arr, int size) {
   int maxNormal = maximumSumSubarray(arr, size);

   if (maxNormal < 0) {
      return (maxNormal);
   }

   int totalSum = 0;

   for (int i = 0; i < size; i++) {
      totalSum += arr[i];
      arr[i]    = -arr[i];
   }
   int maxCircular = totalSum + maximumSumSubarray(arr, size);

   return (max(maxCircular, maxNormal));
}

int main() {
   int arr[]      = { 8, -4, 3, -5, 4 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << maximumSumCircularSubarray(arr, size);
   return (0);
}
