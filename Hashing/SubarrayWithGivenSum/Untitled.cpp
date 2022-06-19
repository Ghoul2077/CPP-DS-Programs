#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds if given array contains any subarray with given sum in
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Boolean value based on whether subarray with sum exists or not
 */
bool subarrayWithGivenSumNaive(int *arr, int size, int sum) {
   for (int i = 0; i < size; i++) {
      int currSum = 0;

      for (int j = i; j < size; j++) {
         currSum += arr[j];

         if (currSum == sum) {
            cout << "Found";
            return (true);
         }
      }
   }

   cout << "Not Found";
   return (false);
}

/**
 * @brief      Finds if given array contains any subarray with given sum in
 *             O(n) time complexity and O(n) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Boolean value based on whether subarray with sum exists or not
 */
bool subarrayWithGivenSum(int *arr, int size, int sum) {
   unordered_set<int> sum_map;
   int prefix_sum = 0;

   sum_map.insert(sum);

   for (int i = 0; i < size; i++) {
      prefix_sum += arr[i];

      if (sum_map.count(prefix_sum) == 1) {
         cout << "Found";
         return (true);
      }

      int extra_sum = sum + prefix_sum;
      sum_map.insert(extra_sum);
   }

   cout << "Not Found";
   return (false);
}

/**
 * @brief      Finds the subarray with the given sum. The idea is to use window
 *             sum apporach where we keep a window using start and stop pointers
 *             and calculate it's sum. According the current sum of the window
 *             we change value of start and stop index, if sum is greater we
 *             subtract the current start and shift starting index forward by 1
 *             and if it is smaller then we move stop index forward by 1 and add
 *             the value at the index. We either perform this process until we
 *             reach the given sum or either of the start or stop become equal
 *             to the size of the array. It's time complexity is O(N) and it's
 *             space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 * @param[in]  sum   The sum to find
 *
 * @return     Boolean value based on whether subarray with sum exists or not
 */
bool subarrayWithGivenSumOptimized(int *arr, int size, int sum) {
   int start = 0, stop = 0;
   int rollingSum = arr[0];

   while (start < n && stop < n) {
      if (rollingSum == sum) {
         return (true);
      } else if (rollingSum < sum) {
         rollingSum += arr[++stop];
      } else {
         rollingSum -= arr[start++];
      }
   }

   return (false);
}

int main() {
   int arr[] = { 5, 8, 6, 13, 3, -1 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 14;

   subarrayWithGivenSum(arr, size, sum);
   return (0);
}
