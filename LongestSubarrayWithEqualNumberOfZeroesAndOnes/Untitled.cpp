#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds the longest subarray with equal number of zeroes and ones
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Max length subarray with equal zeroes and ones
 */
int longestSubarrayWithEqualNumberOfZeroesAndOnesNaive(int *arr, int size) {
   int maxLength = 0;

   for (int i = 0; i < size; i++) {
      int onesCount = 0, zeroesCount = 0;

      for (int j = i; j < size; j++) {
         if (arr[j] == 0) {
            zeroesCount++;
         } else {
            onesCount++;
         }

         if (zeroesCount == onesCount) {
            maxLength = max(maxLength, zeroesCount * 2);
         }
      }
   }

   return (maxLength);
}

/**
 * @brief      Finds the longest subarray with equal number of zeroes and ones
 *             Q(n) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Max length subarray with equal zeroes and ones
 */
int longestSubarrayWithEqualNumberOfZeroesAndOnes(int *arr, int size) {
   int longestSubArraySize = 0, prefixSum = 0;
   unordered_map<int, int> sumToArraySizeMap;

   for (int i = 0; i < size; i++) {
      if (arr[i] == 0) {
         arr[i] = -1;
      }
   }

   for (int i = 0; i < size; i++) {
      prefixSum += arr[i];

      if (prefixSum == 0) {
         longestSubArraySize = max(i + 1, longestSubArraySize);
      }

      if (sumToArraySizeMap.count(prefixSum) == 1) {
         longestSubArraySize =
            max(longestSubArraySize, i - sumToArraySizeMap[prefixSum]);
      }

      if (sumToArraySizeMap.count(prefixSum) == 0) {
         sumToArraySizeMap.insert({ prefixSum, i });
      }
   }

   return (longestSubArraySize);
}

int main() {
   int arr[] = { 0, 1, 1, 0, 1, 1, 1, 0 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << longestSubarrayWithEqualNumberOfZeroesAndOnes(arr, size);
   return (0);
}
