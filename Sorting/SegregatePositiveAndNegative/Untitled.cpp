#include <bits/stdc++.h>
#include <experimental/random>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

/**
 * @brief      This is naive because this uses O(n) space and for the same
 *             is not in place.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void segregatePositiveAndNegativeNaive(int *arr, int size) {
   int *newArr  = new int[size];
   int  counter = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] < 0) {
         newArr[counter++] = arr[i];
      }
   }

   for (int i = 0; i < size; i++) {
      if (arr[i] >= 0) {
         newArr[counter++] = arr[i];
      }
   }

   for (int i = 0; i < size; i++) {
      arr[i] = newArr[i];
   }
}

int hoarePartitionModified(int *arr, int size) {
   int i = -1, j = size;

   while (true) {
      do {
         i++;
      } while (arr[i] < 0);

      do {
         j--;
      } while (arr[j] > 0);

      if (i >= j) {
         return (j);
      }
      swap(arr[i], arr[j]);
   }
}

void segregatePositiveAndNegative(int *arr, int size) {
   hoarePartitionModified(arr, size);
}

int main() {
   int arr[] = { 15, -3, -2, 8 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   segregatePositiveAndNegative(arr, size);
   printArr(arr, size);
   return (0);
}
