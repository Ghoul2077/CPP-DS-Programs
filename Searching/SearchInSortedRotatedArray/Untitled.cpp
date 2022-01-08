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

int binarySearch(int *arr, int size, int elem) {
   int start = 0, stop = size;

   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] < elem) {
         start = mid + 1;
      } else if (arr[mid] > elem) {
         stop = mid - 1;
      } else {
         return (mid);
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
   int mid = (size - 1) / 2;

   if (arr[mid] == elem) {
      return (mid);
   }

   if ((arr[mid] > arr[0]) && (arr[mid] >= elem) && (arr[0] <= elem)) {
      return (binarySearch(arr, mid + 1, elem));
   } else if ((arr[mid] < arr[size - 1]) && (arr[mid] <= elem) &&
              (arr[size - 1] >= elem)) {
      return (binarySearch(&arr[mid], mid + 1, elem));
   } else {
      int res;

      if (arr[mid] > arr[0]) {
         res = searchInRotatedArray(&arr[mid + 1], mid, elem);
      } else if (arr[mid] < arr[size - 1]) {
         res = searchInRotatedArray(arr, mid - 1, elem);
      }

      if (res != -1) {
         return (res + mid + 1);
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
