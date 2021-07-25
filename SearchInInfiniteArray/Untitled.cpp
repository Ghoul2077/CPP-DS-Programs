#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief      Search for an element in an array of infinite size (Which means
 *             size will be unknown) in O(pos) time complexity
 *
 * @param      arr      The arr
 * @param[in]  size     The size
 * @param[in]  element  The element
 *
 * @return     Position of element in infinite array
 */
int searchInfiniteSizedSortedArrayNaive(int *arr, int size, int element) {
   int counter = 0;

   while (true) {
      if (arr[counter] == element) {
         return(counter);
      } else if (arr[counter] > element) {
         return(-1);
      }
      counter++;
   }
   return(-1);
}

int binarySearch(int *arr, int start, int stop, int element) {
   while (start <= stop) {
      int mid = (start + stop) / 2;

      if (arr[mid] < element) {
         start = mid + 1;
      } else if (arr[mid] > element) {
         stop = mid - 1;
      } else {
         return(mid);
      }
   }
   return(-1);
}

/**
 * @brief      Search for an element in an array of infinite size (Which means
 *             size will be unknown) in O(logPos) time complexity by using binary
 *             search while getting upperbound beforehand
 *
 * @param      arr      The arr
 * @param[in]  size     The size
 * @param[in]  element  The element
 *
 * @return     Position of element in infinite array
 */
int searchInfiniteSizedSortedArray(int *arr, int size, int element) {
   if (arr[0] == element) {
      return(0);
   }
   int i;

   for (i = 1; i < size; i *= 2) {
      if (arr[i] > element) {
         break;
      } else if (arr[i] == element) {
         return(i);
      }
   }
   return(binarySearch(arr, 0, i, element));
}

int main() {
   int arr[]   = { 1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000 };
   int element = 21;
   int size    = sizeof(arr) / sizeof(arr[0]);

   // cout << searchInfiniteSizedSortedArrayNaive(arr, size, element) << endl;
   cout << searchInfiniteSizedSortedArray(arr, size, element);
   return(0);
}
