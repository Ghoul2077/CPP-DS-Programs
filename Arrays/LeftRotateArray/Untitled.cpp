#include <bits/stdc++.h>
using namespace std;

// Utility functions
void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

/**
 * @brief      Rotate array counterclockwise once in O(n) time complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void LeftRotateArray(int *arr, int size) {
   int temp = arr[0];
   int i;

   for (i = 1; i < size; i++) {
      arr[i - 1] = arr[i];
   }
   arr[i - 1] = temp;
}

/**
 * @brief      Rotate array counterclockwise by d characters in O(nd) time
 *             complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  d     Number of elments to left shift by
 */
void LeftRotateArrayBydNaive(int *arr, int size, int d) {
   for (int i = 0; i < d; i++) {
      LeftRotateArray(arr, size);
   }
}

/**
 * @brief      Rotate array counterclockwise by d characters in O(n) time
 *             complexity and Q(d) auxillary space
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  d     Number of charaters to shift left by
 */
void LeftRotateArrayByd(int *arr, int size, int d) {
   int *tempArr = new int[d];

   for (int i = d - 1; i >= 0; i--) {
      tempArr[i] = arr[i];
   }

   for (int i = d; i < size; i++) {
      arr[i - d] = arr[i];

      if (i >= size - d) {
         arr[i] = tempArr[i - size + d];
      }
   }
}

/**
 * @brief      Rotate array counterclockwise by d characters in O(n) time
 *             complexity
 *
 * @param      arr   The array
 * @param[in]  size  The size
 * @param[in]  d     Number of charaters to shift left by
 */
void LeftRotateArrayBydReversalAlgorithm(int *arr, int size, int d) {
   reverse(arr,     arr + d);
   reverse(arr + d, arr + size - d);
   reverse(arr,     arr + size);
}

int main() {
   int arr[]      = { 0, 33, 33, 0, 30, 30, 1, 22, 69, 90, 88 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   // LeftRotateArray(arr, size);
   // LeftRotateArrayByd(arr, size, 5);
   // LeftRotateArrayBydNaive(arr, size, 5);
   LeftRotateArrayBydReversalAlgorithm(arr, size, 5);
   printArr(arr, size);
   return (0);
}
