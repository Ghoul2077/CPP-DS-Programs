#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Determines if array sub array contains zero sum in O(n^2) time
 *             complexity and Q(1) space complexity. Subarrays are array
 *             contiguous elements only.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     True if zero sum, False otherwise.
 */
bool hasZeroSumNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int currSum = 0;

      for (int j = i; j < size; j++) {
         currSum += arr[j];

         if (currSum == 0) {
            cout << "Found";
            return (true);
         }
      }
   }
   cout << "Not Found";
   return (false);
}

/**
 * @brief      Determines if array sub array contains zero sum in O(n) time
 *             complexity and O(n) space complexity. Subarrays are array
 *             contiguous elements only.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     True if zero sum, False otherwise.
 */
bool hasZeroSum(int *arr, int size) {
   int prefix_sum = 0;
   unordered_set<int> prefix_sum_set;

   for (int i = 0; i < size; i++) {
      prefix_sum += arr[i];

      if ((prefix_sum_set.count(prefix_sum) == 1) || (prefix_sum == 0)) {
         cout << "Found" << endl;
         return (true);
      }
      prefix_sum_set.insert(prefix_sum);
   }

   cout << "Not Found" << endl;
   return (false);
}

int main() {
   int arr[] = { -1, 4, -3, 5, 1 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   hasZeroSum(arr, size);
   return (0);
}
