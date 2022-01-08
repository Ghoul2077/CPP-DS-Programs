#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Determines if array is sorted reccursively.
 *
 * @param      arr         The arr
 * @param[in]  size        The size
 * @param[in]  startIndex  The start index
 *
 * @return     True if arr sorted reccursive, False otherwise.
 */
bool findIfSortedReccursive(int arr[], int size, int startIndex = 0) {
   if (size == 2) {
      return (arr[startIndex] <= arr[startIndex + 1] ? true : false);
   } else
   if (arr[startIndex] > arr[startIndex + 1]) {
      return (false);
   } else {
      return (findIfSortedReccursive(arr, size - 1, startIndex + 1));
   }
}

/**
 * @brief      Finds if array is sorted naive in O(n**2) time complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     True if sorted else False
 */
bool findIfSortedNaive(int *arr, int size) {
   int flag = true;

   for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
         if (arr[i] > arr[j]) {
            flag = false;
            break;
         }
      }
   }
   return (flag);
}

/**
 * @brief      Finds if array is sorted naive in O(n) time complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     True if sorted else False
 */
bool findIfSorted(int *arr, int size) {
   int flag = true;

   for (int i = 1; i < size; i++) {
      if (arr[i] < arr[i - 1]) {
         flag = false;
         break;
      }
   }
   return (flag);
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5 };

   cout << (findIfSortedReccursive(arr, 5) ? "Sorted" : "Not Sorted");
}
