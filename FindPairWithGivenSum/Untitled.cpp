#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds all pairs in an array with a given sum in O(n^2) time
 *             complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Boolean values indicating if any such pair exists or not
 */
bool findPairWithSumInArrayNaive(int *arr, int size, int sum) {
   bool isPairPresent = false;

   for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
         if ((arr[i] + arr[j]) == sum) {
            cout << arr[i] << " + " << arr[j] << " = " << sum << endl;
            isPairPresent = true;
         }
      }
   }

   return (isPairPresent);
}

/**
 * @brief      Finds a pair with a given sum in array by applying sorting in
 *             O(nlogn) time complexity and Q(1) space complexity. It has
 *             advantage over hashmap method because of space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 */
void findPairWithSumInArray(int *arr, int size, int sum) {
   sort(arr, arr + size);
   int low = 0, high = size - 1;

   while (low <= high) {
      int currSum = arr[low] + arr[high];

      if (currSum == sum) {
         cout << arr[low] << " + " << arr[high] << " = " << sum;
         break;
      } else if (currSum < sum) {
         low += 1;
      } else {
         high -= 1;
      }
   }
}

/**
 * @brief      Finds all pairs in an array with a given sum using hashmap in
 *             Q(n) time complexity and O(n) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Boolean values indicating if any such pair exists or not
 */
bool findPairWithSumInArrayOptimized(int *arr, int size, int sum) {
   unordered_map<int, int> encounteredMap;
   bool isPairPresent = false;

   for (int i = 0; i < size; i++) {
      int diff = sum - arr[i];

      if (encounteredMap.count(arr[i]) == 1) {
         int pair = encounteredMap[arr[i]];
         cout << arr[i] << " + " << pair << " = " << sum << endl;
         isPairPresent = true;
      } else {
         encounteredMap.insert({ diff, arr[i] });
      }
   }

   return (isPairPresent);
}

int main() {
   int arr[] = { 3, 2, 5, 8, 15, -8 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 7;

   findPairWithSumInArray(arr, size, sum);
   return (0);
}
