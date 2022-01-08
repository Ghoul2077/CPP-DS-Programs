#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds the longest subarray with given sum in O(n^2) time
 *             complexity and Q(1) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Length of longest subarray
 */
int longestSubarrayWithGivenSumNaive(int *arr, int size, int sum) {
   int maxSize = INT_MIN;

   for (int i = 0; i < size; i++) {
      int currSum = 0;

      for (int j = i; j < size; j++) {
         currSum += arr[j];

         if (currSum == sum) {
            maxSize = max(j - i + 1, maxSize);
         }
      }
   }

   return (maxSize);
}

/**
 * @brief      Finds the longest subarray with given sum in Q(n) time
 *             complexity and O(n) space complexity. We use hashmap and store
 *             prefix sum as key and index as value and then get to our answer.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Length of longest subarray
 */
int longestSubarrayWithGivenSum(int *arr, int size, int sum) {
   int maxSize   = 0;
   int prefixSum = 0;
   unordered_map<int, int> extraSumToIndexMap;

   for (int i = 0; i < size; i++) {
      prefixSum += arr[i];

      if (prefixSum == sum) {
         maxSize = max(i + 1, maxSize);
         continue;
      }

      if (extraSumToIndexMap.count(prefixSum - sum) == 1) {
         maxSize = max(maxSize, i - extraSumToIndexMap[prefixSum - sum]);
      }

      if (extraSumToIndexMap.count(prefixSum) == 0) {
         extraSumToIndexMap.insert({ prefixSum, i });
      }
   }

   return (maxSize);
}

int main() {
   int arr[] = { 5, -6, -4, 0, 4, 6, -3 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 3;

   cout << longestSubarrayWithGivenSum(arr, size, sum);
   return (0);
}
