#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds the size of longest consecutive subsequence, a subsequence
 *             is like x, x + 1, x + 2...x + n no matter the order they occure.
 *             It's time complexity is O(nlogn) and space complexity is Q(1).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Size of longest subsequence
 */
int longestConsecutiveSubsequenceNaive(int *arr, int size) {
   sort(arr, arr + size);
   int currSize = 1, maxSize = 1;

   for (int i = 1; i < size; i++) {
      if (arr[i] == arr[i - 1] + 1)  {
         currSize++;
      } else if (arr[i] != arr[i - 1]) {
         maxSize  = max(maxSize, currSize);
         currSize = 1;
      }
   }

   return (maxSize);
}

/**
 * @brief      Finds the size of longest consecutive subsequence, a subsequence
 *             is like x, x + 1, x + 2...x + n no matter the order they occure.
 *             It's time complexity is O(2n) and space complexity is O(n).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Size of longest subsequence
 */
int longestConsecutiveSubsequence(int *arr, int size) {
   int maxCount = 1;
   unordered_set<int> arrayValuesSet(arr, arr + size);

   for (int i = 0; i < size; i++) {
      int count = 0;
      int curr  = arr[i];

      if (arrayValuesSet.count(arr[i] - 1) == 0) {
         while (true) {
            if (arrayValuesSet.count(curr++)) {
               count++;
            } else {
               break;
            }
         }
      }

      maxCount = max(maxCount, count);
   }

   return (maxCount);
}

int main() {
   int arr[] = { 1, 9, 3, 4, 2, 20 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << longestConsecutiveSubsequence(arr, size);
   return (0);
}
