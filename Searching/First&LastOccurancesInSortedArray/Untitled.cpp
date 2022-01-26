#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds a first occurance of a sorted array in O(logn) time and
 *             Q(1) space complexity using modified binary search.
 *             This method is better than reccursive because it take Q(1) space
 *             as compared to O(n) space
 *
 * @param      arr     The array
 * @param[in]  size    The size
 * @param[in]  toFind  To find
 *
 * @return     Index of first occurance
 */
int findFirstOccurance(int *arr, int size, int toFind) {
   int start = 0, stop = size - 1;

   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] > toFind) {
         stop = mid - 1;
      } else if (arr[mid] < toFind) {
         start = mid + 1;
      } else {
         if ((mid == 0) || (arr[mid - 1] != arr[mid])) {
            return (mid);
         } else {
            stop = mid - 1;
         }
      }
   }
   return (-1);
}

/**
 * @brief      Finds a last occurance of a sorted array in O(logn) time and
 *             Q(1) space complexity using modified binary search.
 *             This method is better than reccursive because it take Q(1) space
 *             as compared to O(n) space
 *
 * @param      arr     The array
 * @param[in]  size    The size
 * @param[in]  toFind  To find
 *
 * @return     Index of last occurance
 */
int findLastOccurance(int *arr, int size, int toFind) {
   int start = 0, stop = size - 1;

   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] > toFind) {
         stop = mid - 1;
      } else if (arr[mid] < toFind) {
         start = mid + 1;
      } else {
         if ((mid == size - 1) || (arr[mid + 1] != arr[mid])) {
            return (mid);
         } else {
            start = mid + 1;
         }
      }
   }
   return (-1);
}

int main() {
   int arr[]      = { 1, 8, 30, 30, 30, 30, 35, 50, 100 };
   int element    = 30;
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << "First occurance : " <<
      findFirstOccurance(arr, size, element) << endl;
   cout << "Last occurance  : " << findLastOccurance(arr, size, element);
   return (0);
}
