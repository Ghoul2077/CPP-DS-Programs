#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds longest subarray in 2 given boolean arrays of equal sizes
 *             given the condition that the sizes of subarrays in both array
 *             should be same. Time complexity is O(n^2) and space complexity
 *             is Q(1).
 *
 * @param      arr1  The array 1
 * @param      arr2  The array 2
 * @param[in]  size  The size
 *
 * @return     Size of longest subarray
 */
int longestSubarrayWithCommonSumNaive(int *arr1, int *arr2, int size) {
   int maxLen = 0;

   for (int i = 0; i < size; i++) {
      int sum1 = 0, sum2 = 0;

      for (int j = i; j < size; j++) {
         sum1 += arr1[j];
         sum2 += arr2[j];

         if (sum1 == sum2) {
            maxLen = max(maxLen, j);
         }
      }
   }

   return (maxLen);
}

/**
 * @brief      Finds longest subarray in 2 given boolean arrays of equal sizes
 *             given the condition that the sizes of subarrays in both array
 *             should be same. In this approach we are converting our problem
 *             to longest subarray with sum 0 by subtracting the 2 arrays.
 *             Time complexity is Q(n) and space complexity is Q(n).
 *
 * @param      arr1  The array 1
 * @param      arr2  The array 2
 * @param[in]  size  The size
 *
 * @return     Size of longest subarray
 */
int longestSubarrayWithCommonSum(int *arr1, int *arr2, int size) {
   int *newArr    = new int[size * 2];
   int  maxLen    = 0;
   int  prefixSum = 0;
   unordered_map<int, int> sumToLengthMap;

   for (int i = 0; i < size; i++) {
      newArr[i] = arr1[i] - arr2[i];
   }

   for (int i = 0; i < size; i++) {
      prefixSum += newArr[i];

      if (prefixSum == 0) {
         maxLen = max(maxLen, i + 1);
      }

      if (sumToLengthMap.count(prefixSum) == 0) {
         sumToLengthMap.insert({ prefixSum, i });
      } else {
         maxLen = max(maxLen, i - sumToLengthMap[prefixSum]);
      }
   }

   return (maxLen);
}

int main() {
   int arr1[] = { 0, 0, 1, 0 };
   int arr2[] = { 1, 1, 1, 1 };
   int size   = sizeof(arr2) / sizeof(arr2[0]);

   cout << longestSubarrayWithCommonSum(arr1, arr2, size);
   return (0);
}
