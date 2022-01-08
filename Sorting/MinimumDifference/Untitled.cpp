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

int hoarePartitionOptimized(int *arr, int start, int stop) {
   int randNum = std::experimental::randint(start, stop);

   swap(arr[randNum], arr[start]);
   return (hoarePartition(arr, start, stop));
}

void quickSort(int *arr, int start, int stop) {
BEGIN:

   if (start < stop) {
      int pivotIndex = hoarePartitionOptimized(arr, start, stop);
      quickSort(arr, start, pivotIndex);
      start = pivotIndex + 1;
      goto BEGIN;
   }
}

/**
 * @brief      Finds minimum difference of the given array in O(n^2) time
 *             time complexity Q(1) space complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Minimum difference
 */
int minDifferenceNaive(int *arr, int size) {
   int minDiff = INT_MAX;

   if (size == 1) {
      return (minDiff);
   }

   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         int currDiff = abs(arr[i] - arr[j]);
         minDiff = min(currDiff, minDiff);
      }
   }

   return (minDiff);
}

/**
 * @brief      Finds minimum difference of the given array by sorting first and
 *             then traversing array from left to right. It's time complexity is
 *             O(logn) and space complexity is Q(1)
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Minimum difference
 */
int minDifference(int *arr, int size) {
   int minDiff = INT_MAX;

   if (size == 1) {
      return (minDiff);
   }
   quickSort(arr, 0, size - 1);

   for (int i = 1; i < size; i++) {
      int currDiff = abs(arr[i] - arr[i - 1]);
      minDiff = min(currDiff, minDiff);
   }

   return (minDiff);
}

int main() {
   int arr[] = { 15, 3, 8, 16, 0, 2, 99 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << minDifference(arr, size);
   return (0);
}
