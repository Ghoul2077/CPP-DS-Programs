#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

void swap(int&num1, int&num2) {
   int temp = num1;

   num1 = num2;
   num2 = temp;
}

int hoardePartition(int *arr, int start, int stop) {
   int pivot = arr[start];
   int i = start - 1, j = stop + 1;

   while (true) {
      do {
         i++;
      } while (arr[i] < pivot);
      do {
         j--;
      } while (arr[j] > pivot);
      if (i >= j) {
         return(j);
      }
      swap(arr[i], arr[j]);
   }
}

/**
 * @brief      Quick sort using hoarde partition in O(nlogn) time complexity.
 *             Better than lomuto partitioning method
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  stop   The stop
 */
void quickSortHoarde(int *arr, int start, int stop) {
   if (start < stop) {
      int pivotIndex = hoardePartition(arr, start, stop);
      quickSortHoarde(arr, start, pivotIndex - 1);
      quickSortHoarde(arr, pivotIndex + 1, stop);
   }
}

int main() {
   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   quickSortHoarde(arr, 0, size - 1);
   printArr(arr, size);
   return(0);
}
