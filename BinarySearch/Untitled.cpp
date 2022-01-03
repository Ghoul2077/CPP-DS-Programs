#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds if array is sorted naive in O(n) time complexity.
 *
 * @param      arr   The arr
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

int binarySearchIterative(int *arr, int size, int toSearch) {
   const bool isSorted = findIfSorted(arr, size);

   if (isSorted) {
      int start = 0, end = size - 1;

      while (start <= end) {
         int mid = (start + end) / 2;

         if (arr[mid] == toSearch) {
            return (mid);
         } else if (arr[mid] > toSearch) {
            end = mid - 1;
         } else {
            start = mid + 1;
         }
      }
   } else {
      cout << "Array is not sorted" << endl;
   }
   return (-1);
}

int binarySearchReccursive(int *arr, int size, int start, int end,
                           int toSearch) {
   const bool isSorted = findIfSorted(arr, size);

   if (isSorted) {
      if (start > end) {
         return (-1);
      }

      int mid = (start + end) / 2;

      if (arr[mid] == toSearch) {
         return (mid);
      } else if (arr[mid] < toSearch) {
         return (binarySearchReccursive(arr, size, mid + 1, end, toSearch));
      } else {
         return (binarySearchReccursive(arr, size, start, mid - 1, toSearch));
      }
   } else {
      cout << "Array is not sorted" << endl;
   }
   return (-1);
}

int main() {
   int arr[]      = { 10, 10 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << binarySearchReccursive(arr, size, 0, size - 1, 4);
   return (0);
}
