#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

/**
 * @brief      Naive partitioning where we put a given pivot element in its right
 *             place with all smaller elements to its left and all greater elements
 *             to its right in O(n) time complexity and Q(n) space complexity.
 *
 * @param      arr         The array
 * @param[in]  start       The start
 * @param[in]  stop        The stop
 * @param[in]  pivotIndex  The pivot index
 *
 * @return     Final index of pivot element
 */
int naivePartitioning(int *arr, int start, int stop, int pivotIndex) {
   int  arrSize = stop - start + 1;
   int *newArr  = new int[arrSize];
   int  newIndexOfPivot;
   int  counter = 0;

   for (int i = start; i <= stop; i++) {
      if ((i != pivotIndex) && (arr[i] <= arr[pivotIndex])) {
         newArr[counter++] = arr[i];
      }
   }

   newIndexOfPivot   = counter;
   newArr[counter++] = arr[pivotIndex];

   for (int i = start; i <= stop; i++) {
      if (arr[i] > arr[pivotIndex]) {
         newArr[counter++] = arr[i];
      }
   }

   for (int i = start; i <= stop; i++) {
      arr[i] = newArr[i - start];
   }

   delete[] newArr;
   return (newIndexOfPivot);
}

/**
 * @brief      Lomuto partitioning where we put a given pivot element in its right
 *             place with all smaller elements to its left and all greater elements
 *             to its right in O(n) time complexity and Q(1) space complexity.
 *
 * @param      arr         The array
 * @param[in]  start       The start
 * @param[in]  stop        The stop
 * @param[in]  pivotIndex  The pivot index
 *
 * @return     Final index of pivot element
 */
int lomutoPartition(int *arr, int start, int stop) {
   int pivot = arr[stop];
   int i     = start - 1;

   for (int j = start; j <= stop - 1; j++) {
      if (arr[j] < pivot) {
         i++;
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[i + 1], arr[stop]);
   return (i + 1);
}

/**
 * @brief      Hoare partitioning where we find a given pivot element's sorted
 *             position in O(n) time complexity and Q(1) space complexity. This
 *             does not ensure that smaller elements are to the left and greater
 *             to the right in process of finding final index.
 *
 * @param      arr         The array
 * @param[in]  start       The start
 * @param[in]  stop        The stop
 * @param[in]  pivotIndex  The pivot index
 *
 * @return     Final index of pivot element
 */
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

int main() {
   int arr[]          = { 40, 30, 20, 10 };
   int size           = sizeof(arr) / sizeof(arr[0]);
   int partitionIndex = 3;

   cout << hoarePartition(arr, 0, size - 1);
   return (0);
}
