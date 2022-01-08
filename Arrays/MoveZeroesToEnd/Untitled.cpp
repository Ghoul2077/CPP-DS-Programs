#include <bits/stdc++.h>
using namespace std;

// Utility functions
void printArr(int *arr,
              int  size);
void swap(int *arr,
          int  index1,
          int  index2);

/**
 * @brief      Move zeroes to end in O(n^2) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void moveZeroesToEndNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      if (arr[i] == 0) {
         for (int j = i + 1; j < size; j++) {
            if (arr[j] != 0) {
               swap(arr, i, j);
               break;
            }
         }
      }
   }
}

/**
 * @brief      Move zeroes to end in O(n) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void moveZeroesToEnd(int *arr, int size) {
   int zeroCount = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] == 0) {
         zeroCount++;
      } else {
         const int replaceIndex = i - zeroCount;
         swap(arr, i, replaceIndex);
      }
   }
}

void swap(int *arr, int index1, int index2) {
   int temp = arr[index1];

   arr[index1] = arr[index2];
   arr[index2] = temp;
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[]      = { 0, 33, 33, 0, 30, 30, 1, 22, 69, 90, 88 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   moveZeroesToEnd(arr, size);
   printArr(arr, size);
   return (0);
}
