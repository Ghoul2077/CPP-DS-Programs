#include <bits/stdc++.h>
using namespace std;

int linearSearch(int *arr, int size, int elem) {
   for (int i = 0; i < size; i++) {
      if (arr[i] == elem) {
         return (i);
      }
   }
   return (-1);
}

int searchInRotatedArrayNaive(int *arr, int size, int elem) {
   return (linearSearch(arr, size, elem));
}

/**
 * @brief      Searching in a sorted rotated array in O(logn) time complexity
 *             by exploiting the fact that at any given time half of the array
 *             will be completely sorted and other will be not, so find the
 *             range in which your number lies then find it using binary search
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  elem  The element
 *
 * @return     Index of element if found else  -1
 */
int searchInRotatedArray(int *arr, int size, int elem) {
   int l = 0, h = size - 1;

   while (l <= h) {
      int mid = (l + h) / 2;

      if (arr[mid] == elem) {
         return (mid);
      } else if (arr[mid] >= arr[l]) {
         if ((elem >= arr[l]) && (elem < arr[mid])) {
            h = mid - 1;
         } else {
            l = mid + 1;
         }
      } else {
         if ((elem > arr[mid]) && (elem <= arr[h])) {
            l = mid + 1;
         } else {
            h = mid - 1;
         }
      }
   }

   return (-1);
}

int main() {
   int arr[] = { 15, 20, 40, 60, 80, 100, 200, 500, 1000, 1, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int elem  = 15;

   cout << searchInRotatedArray(arr, size, elem);
   return (0);
}
