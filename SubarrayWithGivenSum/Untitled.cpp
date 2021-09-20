#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds if given array contains any subarray with given sum in
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
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
 * @param      arr   The arr
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

int main() {
   int arr[] = { 5, 8, 6, 13, 3, -1 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 14;

   subarrayWithGivenSum(arr, size, sum);
   return (0);
}
