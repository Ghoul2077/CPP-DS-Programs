#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

// Utility functions
void swap(int *arr, int index1, int index2) {
   int temp = arr[index1];

   arr[index1] = arr[index2];
   arr[index2] = temp;
}

void reverseArray(int *arr, int size) {
   for (int i = 0; i < size / 2; i++) {
      int indexToSwap = size - i - 1;
      swap(arr, indexToSwap, i);
   }
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void merge(int arr[], int start1, int end1, int start2, int end2) {
   int  i        = start1;
   int  j        = start2;
   int  counter  = 0;
   int  size     = end2 - start1 + 1;
   int *finalArr = new int[size];

   while (i <= end1 && j <= end2) {
      if (arr[i] <= arr[j]) {
         finalArr[counter++] = arr[i++];
      } else {
         finalArr[counter++] = arr[j++];
      }
   }

   while (i <= end1) {
      finalArr[counter++] = arr[i++];
   }

   while (j <= end2) {
      finalArr[counter++] = arr[j++];
   }

   for (int m = start1; m < start1 + size; m++) {
      arr[m] = finalArr[m - start1];
   }

   delete[] finalArr;
}

/**
 * @brief      Print frequency of each unique element of a sorted array in Q(n)
 *             time complexity and Q(1) auxillary space complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void frequencySortedArray(int *arr, int size) {
   int i;
   int count = 0;
   int curr  = arr[0];

   for (i = 0; i < size; i++) {
      if (arr[i] == curr) {
         count++;
      } else {
         cout << arr[i - 1] << "  " << count << endl;
         curr  = arr[i];
         count = 1;
      }
   }
   cout << arr[i - 1] << "  " << count << endl;
}

void mergeSort(int *arr, int start, int end) {
   if (start < end) {
      int mid = (start + end) / 2;
      mergeSort(arr, start,   mid);
      mergeSort(arr, mid + 1, end);
      merge(arr, start, mid, mid + 1, end);
   }
}

/**
 * @brief      Print frequency of each unique element of an unsorted array in
 *             O(nlogn) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void frequencyNaive(int *arr, int size) {
   mergeSort(arr, 0, size - 1);
   frequencySortedArray(arr, size);
}

int main() {
   int arr[]      = { 10, 10, 25, 30, 30 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   frequencyNaive(arr, size);
   return (0);
}
