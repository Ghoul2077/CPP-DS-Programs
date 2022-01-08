#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds the largest in given array in O(n**2) complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     Biggest value from array
 */
int findLargestNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int flag = true;

      for (int j = 0; j < size; j++) {
         if (arr[j] > arr[i]) {
            flag = false;
         }
      }

      if (flag) {
         return (arr[i]);
      }
   }
   return (-1);
}

/**
 * @brief      Finds the largest in O(n) time complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     Biggest value from array
 */
int findLargestLinear(int *arr, int size) {
   if (size == 1) {
      return (arr[0]);
   }
   int max = arr[0];

   for (int i = 1; i < size; i++) {
      if (arr[i] > max) {
         max = arr[i];
      }
   }
   return (max);
}

/**
 * @brief      Finds the largest using reccursion in O(n).
 *
 * @param      arr    The arr
 * @param[in]  start  The starting index
 * @param[in]  stop   The last / ending index
 *
 * @return     Biggest value from array
 */
int findLargest(int *arr, int start, int stop) {
   if (start == stop) {
      return (arr[start]);
   }
   int mid = start + floor((stop - start) / 2);

   int max1 = findLargest(arr, start, mid);
   int max2 = findLargest(arr, mid + 1, stop);

   if (max1 > max2) {
      return (max1);
   } else {
      return (max2);
   }
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = { 16, 34, 33, 54, 30, 10, 1, 22, 69, 90, 88 };

   // cout << findLargestLinear(arr, sizeof(arr) / sizeof(arr[0]));
   // cout << findLargestNaive(arr, sizeof(arr) / sizeof(arr[0]));
   cout << findLargest(arr, 0, sizeof(arr) / sizeof(arr[0]));
   return (0);
}
