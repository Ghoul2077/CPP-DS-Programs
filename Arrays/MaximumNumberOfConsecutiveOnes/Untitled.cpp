#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Calculate maximum number of consecutive ones appearing in a
 *             binary array in O(n^2) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Maximum number of ones
 */
int maximumConsecutiveOneNaive(int *arr, int size) {
   int res = 0;

   for (int i = 0; i < size; i++) {
      int currCount = 0;

      for (int j = i; j < size; j++) {
         if (arr[j] == 1) {
            currCount++;
         } else {
            break;
         }
      }

      if (currCount > res) {
         res = currCount;
      }
   }
   return (res);
}

/**
 * @brief      Calculate maximum number of consecutive ones appearing in a
 *             binary array in O(n) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Maximum number of ones
 */
int maximumConsecutiveOne(int *arr, int size) {
   int count = 0;
   int res   = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] == 0) {
         if (count > res) {
            res = count;
         }
         count = 0;
         continue;
      } else {
         count++;
      }
   }

   return (res);
}

int main() {
   int arr[]      = { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << maximumConsecutiveOneNaive(arr, size);
   return (0);
}
