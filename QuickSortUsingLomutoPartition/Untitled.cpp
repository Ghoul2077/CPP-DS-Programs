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

int lomutoPartition(int *arr, int start, int stop) {
   int pivot = arr[stop];
   int i     = start - 1;

   for (int j = start; j < stop; j++) {
      if (arr[j] < pivot) {
         i++;
         swap(arr[j], arr[i]);
      }
   }
   swap(arr[i + 1], arr[stop]);
   return(i + 1);
}

/**
 * @brief      Quick sort using lomuto partition in O(nlogn) time complexity
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  stop   The stop
 */
void quickSortLomuto(int *arr, int start, int stop) {
   if (start < stop) {
      int pivotIndex = lomutoPartition(arr, start, stop);
      quickSortLomuto(arr, start, pivotIndex - 1);
      quickSortLomuto(arr, pivotIndex + 1, stop);
   }
}

int main() {
   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   quickSortLomuto(arr, 0, size - 1);
   printArr(arr, size);
   return(0);
}
