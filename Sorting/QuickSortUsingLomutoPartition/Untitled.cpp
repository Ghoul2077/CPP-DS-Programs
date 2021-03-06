#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
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
   return (i + 1);
}

int lomutoPartitionOptimized(int *arr, int start, int stop) {
   int randNum = rand() % (stop - start + 1);

   swap(arr[stop], arr[stop - randNum]);
   return (lomutoPartition(arr, start, stop));
}

/**
 * @brief      Quick sort using lomuto partition in O(nlogn) average time
 *             complexity and O(n^2) in worst case when not using optimised
 *             partitioning which chooses pivot at random.
 *
 * @param      arr    The array
 * @param[in]  start  The start
 * @param[in]  stop   The stop
 */
void quickSortLomuto(int *arr, int start, int stop) {
   if (start < stop) {
      int pivotIndex = lomutoPartitionOptimized(arr, start, stop);
      quickSortLomuto(arr, start,          pivotIndex - 1);
      quickSortLomuto(arr, pivotIndex + 1, stop);
   }
}

int main() {
   srand(time(0));

   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   quickSortLomuto(arr, 0, size - 1);
   printArr(arr, size);
   return (0);
}
