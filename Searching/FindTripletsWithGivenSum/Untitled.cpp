#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds triplets with given sum in sorted array in O(n^3) time
 *             complexity and Q(1) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 */
void findTripletsWithSumInSortedArrayNaive(int *arr, int size, int sum) {
   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         for (int k = j + 1; k < size; k++) {
            if ((arr[i] + arr[j] + arr[k]) == sum) {
               cout << arr[i] << " + " << arr[j] << " + " << arr[k];
               return;
            }
         }
      }
   }

   cout << "Not Found";
}

/**
 * @brief      Finds triplets with given sum in sorted array in O(n^2) time
 *             complexity and Q(1) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 */
void findTripletsWithSumInSortedArray(int *arr, int size, int sum) {
   for (int i = 0; i < size; i++) {
      int diff = sum - arr[i];
      int low = i + 1, high = size - 1;

      while (low <= high) {
         int currSum = arr[low] + arr[high];

         if (currSum == diff) {
            cout << arr[i] << " + " << arr[low] << " + " << arr[high];
            return;
         } else if (currSum < diff) {
            low += 1;
         } else {
            high -= 1;
         }
      }
   }
   cout << "Not Found";
}

int main() {
   int arr[] = { 1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 321;

   findTripletsWithSumInSortedArray(arr, size, sum);
   return (0);
}
