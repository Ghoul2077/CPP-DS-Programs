#include <iostream>
#include <math.h>
#include <experimental/random>
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

int lomutoPartitionOptimized(int *arr, int start, int stop) {
   int randNum = std::experimental::randint(start, stop);

   swap(arr[stop], arr[randNum]);
   return(lomutoPartition(arr, start, stop));
}

/**
 * @brief      Quick sort using lomuto partition in O(nlogn) average time 
 *             complexity and O(n^2) in worst case when not using optimised
 *             partitioning which chooses pivot at random.
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  stop   The stop
 */
void quickSortLomuto(int *arr, int start, int stop) {
   if (start < stop) {
      int pivotIndex = lomutoPartitionOptimized(arr, start, stop);
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
