#include <bits/stdc++.h>
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
   int randInt = rand() % (stop - start + 1);

   swap(arr[start + randInt], arr[start]);
   return (hoarePartition(arr, start, stop));
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
 * @brief      Find the minimum difference of min and max chocolates when
 *             distributing array of chocolate bags between k kids. Here the
 *             distribution need not be continuous. We find it in O(nlogn) time
 *             complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  k     The number of kids
 *
 * @return     The minimum difference of maximum and minimum distributed chocolates
 */
int minDiffOfMinAndMaxChocolatesBetweenKKids(int *arr, int size, int k) {
   if (k > size) {
      return (-1);
   }

   quickSort(arr, 0, size - 1);
   int minDiff = INT_MAX;

   for (int i = k - 1; i < size; ++i) {
      int currDiff = arr[i] - arr[i - k + 1];
      minDiff = min(minDiff, currDiff);
   }

   return (minDiff);
}

int main() {
   srand(time(0));

   int arr[]   = { 7, 3, 2, 4, 9, 12, 56 };
   int size    = sizeof(arr) / sizeof(arr[0]);
   int kidsNum = 3;

   cout << minDiffOfMinAndMaxChocolatesBetweenKKids(arr, size, kidsNum);
   return (0);
}
