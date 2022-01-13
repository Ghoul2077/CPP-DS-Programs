#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

int hoarePartition(int *arr, int start, int stop) {
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
         return (j);
      }
      swap(arr[i], arr[j]);
   }
}

int hoarePartitionOptimized(int *arr, int start, int stop) {
   int randNum = std::experimental::randint(start, stop);

   swap(arr[start], arr[randNum]);
   return (hoarePartition(arr, start, stop));
}

/**
 * @brief      Quick sort using hoarde partition in O(nlogn) time complexity.
 *             Better than lomuto partitioning method, found to be around 3 times
 *             faster. It has O(n^2) time complexity in worst case if not used
 *             optimised partitioning i.e choosing pivot at random.
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  stop   The stop
 */
void quickSortHoarde(int *arr, int start, int stop) {
   if (start < stop) {
      int pivotIndex = hoarePartitionOptimized(arr, start, stop);
      quickSortHoarde(arr, start,          pivotIndex);
      quickSortHoarde(arr, pivotIndex + 1, stop);
   }
}

int main() {
   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   quickSortHoarde(arr, 0, size - 1);
   printArr(arr, size);
   return (0);
}
