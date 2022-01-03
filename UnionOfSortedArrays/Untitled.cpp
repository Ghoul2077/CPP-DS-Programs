#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

void merge(int *arr, int start1, int stop1, int start2, int stop2) {
   int *newArr = new int[stop2 - start1 + 1];
   int  i = start1, j = start2;
   int  counter = 0;

   while (i <= stop1 && j <= stop2) {
      if (arr[i] <= arr[j]) {
         newArr[counter++] = arr[i++];
      } else {
         newArr[counter++] = arr[j++];
      }
   }

   while (i <= stop1) {
      newArr[counter++] = arr[i++];
   }

   while (j <= stop2) {
      newArr[counter++] = arr[j++];
   }

   for (int i = start1; i <= stop2; i++) {
      arr[i] = newArr[i - start1];
   }

   delete[] newArr;
}

void mergeSort(int *arr, int start, int stop) {
   if (start < stop) {
      int mid = (start + stop) / 2;
      mergeSort(arr, start,   mid);
      mergeSort(arr, mid + 1, stop);
      merge(arr, start, mid, mid + 1, stop);
   }
}

/**
 * @brief      Prints the union of 2 sorted arrays by using the merge operation
 *             from the merge sort. It takes O(m+nlog(m + n)) time complexity
 *             where m & n are the sizes of array respectively, also it take
 *             Q(m + n) space complexity.
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 */
void unionOfSortedArraysNaive(int *arr1, int size1, int *arr2, int size2) {
   int  mergedArrSize = size1 + size2;
   int *mergedArr     = new int[mergedArrSize];
   int  i             = 0;

   for (i = 0; i < size1; i++) {
      mergedArr[i] = arr1[i];
   }

   for (int j = i; j < i + size2; j++) {
      mergedArr[j] = arr2[j - i];
   }
   mergeSort(mergedArr, 0, mergedArrSize - 1);

   for (int i = 0; i < mergedArrSize; i++) {
      if ((i == 0) || (mergedArr[i] != mergedArr[i - 1])) {
         cout << mergedArr[i] << " ";
      }
   }
}

/**
 * @brief      Prints the union of 2 sorted arrays by using the merge operation
 *             from the merge sort. It takes O(m + n) time complexity where m &
 *             n are the sizes of array respectively, also it take Q(1) space
 *             complexity.
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 */
void unionOfSortedArrays(int *arr1, int size1, int *arr2, int size2) {
   int i = 0, j = 0;

   while (i < size1 && j < size2) {
      if ((i > 0) && (arr1[i] == arr1[i - 1])) {
         i++;
         continue;
      } else if ((j > 0) && (arr2[j] == arr2[j - 1])) {
         j++;
         continue;
      } else if (arr1[i] < arr2[j]) {
         cout << arr1[i++] << " ";
      } else if (arr1[i] > arr2[j]) {
         cout << arr2[j++] << " ";
      } else {
         cout << arr1[i] << " ";
         i++;
         j++;
      }
   }

   while (i < size1) {
      if ((i > 0) && (arr1[i] != arr1[i - 1])) {
         cout << arr1[i++];
      }
   }

   while (j < size2) {
      if ((j > 0) && (arr2[j] != arr2[j - 1])) {
         cout << arr2[j++];
      }
   }
}

int main() {
   int arr1[] = { 10, 20, 30, 40 };
   int arr2[] = { 2, 5, 10, 13, 30, 40 };
   int size1  = sizeof(arr1) / sizeof(arr1[0]);
   int size2  = sizeof(arr2) / sizeof(arr2[0]);

   unionOfSortedArraysNaive(arr1, size1, arr2, size2);

   return (0);
}
