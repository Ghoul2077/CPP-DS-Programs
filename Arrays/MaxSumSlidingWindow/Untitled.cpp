#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Calculate max sum of subarray given the size of
 *             subarrays in O(n^2) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  k     The size of subarrays
 *
 * @return     Max sum of subarray
 */
int maxSumOfKElementsNaive(int *arr, int size, int k) {
   int maxSum = INT_MIN;

   for (int i = 0; i < size; i++) {
      int currSum = 0;

      if (i + k < size) {
         for (int j = i; j < i + k; j++) {
            currSum += arr[j];
         }
      } else {
         break;
      }

      if (currSum > maxSum) {
         maxSum = currSum;
      }
   }
   return (maxSum);
}

/**
 * @brief      Calculate max sum of subarray given the size of
 *             subarrays in O(n) time complexity via sliding
 *             window technique
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  k     The size of subarrays
 *
 * @return     Max sum of subarray
 */
int maxSumOfKElements(int *arr, int size, int k) {
   int maxWindowSum = 0;

   for (int i = 0; i < k; i++) {
      maxWindowSum += arr[i];
   }

   int prevWindowSum = maxWindowSum;

   for (int i = k; i < size; i++) {
      int newWindowSum = prevWindowSum - arr[i - k] + arr[i];

      if (newWindowSum > maxWindowSum) { maxWindowSum = newWindowSum; }
      prevWindowSum = newWindowSum;
   }

   return (maxWindowSum);
}

int main() {
   int arr[]      = { 1, 8, 30, -5, 20, 7 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << maxSumOfKElements(arr, size, 3);
   return (0);
}
