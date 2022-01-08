#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

void swap(int& num1, int& num2) {
   int temp = num1;

   num1 = num2;
   num2 = temp;
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

int lomutoPartition(int *arr, int start, int stop) {
   int pivot = arr[stop];
   int i     = -1;

   for (int j = 0; j < stop; j++) {
      if (arr[j] <= pivot) {
         i++;
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[stop], arr[i + 1]);
   return (i + 1);
}

int hoarePartitionOptimized(int *arr, int start, int stop) {
   int randNum = std::experimental::randint(start, stop);

   swap(arr[randNum], arr[start]);
   return (hoarePartition(arr, start, stop));
}

int lomutoPartitionOptimized(int *arr, int start, int stop) {
   int randNum = std::experimental::randint(start, stop);

   swap(arr[randNum], arr[stop]);
   return (lomutoPartition(arr, start, stop));
}

void quickSort(int *arr, int start, int stop) {
Begin:

   if (start < stop) {
      int pivotIndex = hoarePartition(arr, start, stop);
      quickSort(arr, start, pivotIndex);
      start = pivotIndex + 1;
      goto Begin;
   }
}

/**
 * @brief      Finds a kth smallest element in O(nlogn) time complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  k     Kth smallest element to find
 *
 * @return     Kth smallest element
 */
int findKthSmallestElementNaive(int *arr, int size, int k) {
   quickSort(arr, 0, size - 1);
   return (arr[k - 1]);
}

/**
 * @brief      Finds a kth smallest element in O(n) average time complexity and
 *             O(n^2) worst case time complexity. It makes use of lomuto
 *             partitioning like binary search until we get our kth smallest
 *             element as pivot index
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  k     Kth smallest element to find
 *
 * @return     Kth smallest element
 */
int findKthSmallestElement(int *arr, int size, int k) {
   int start = 0, stop = size - 1;

   while (start <= stop) {
      int pivotIndex = lomutoPartitionOptimized(arr, start, stop);

      if (pivotIndex == k - 1) {
         return (arr[pivotIndex]);
      } else if (pivotIndex > k - 1) {
         stop = pivotIndex - 1;
      } else {
         start = pivotIndex + 1;
      }
   }

   return (-1);
}

int main() {
   int arr[] = { 3, 4, 1, 1, 6 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int k     = 4;

   cout << findKthSmallestElement(arr, size, k);
   return (0);
}
