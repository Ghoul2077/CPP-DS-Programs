#include <bits/stdc++.h>
using namespace std;

// Utility functions
void printArr(int *arr,
              int  size);
void swap(int *arr,
          int  index1,
          int  index2);
void reverseArray(int *arr,
                  int  size);

/**
 * @brief      The maximum difference between arr[j] - arr[i] where j > i in
 *             O(n^2) time complexity and Q(1) space complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum difference res
 */
int maximumDifferenceNaive(int *arr, int size) {
   int maxDiff = INT_MIN;

   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         int diff = arr[j] - arr[i];

         if (diff > maxDiff) {
            maxDiff = diff;
         }
      }
   }

   return (maxDiff);
}

/**
 * @brief      The maximum difference between arr[j] - arr[i] where j > i in
 *             O(n) time complexity and Q(1) space complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum difference res
 */
int maximumDifference(int *arr, int size) {
   int min = arr[0], res = arr[1] - arr[0];

   for (int i = 1; i < size; i++) {
      if (res < arr[i] - min) {
         res = arr[i] - min;
      }

      if (arr[i] < min) {
         min = arr[i];
      }
   }
   return (res);
}

void reverseArray(int *arr, int size) {
   for (int i = 0; i < size / 2; i++) {
      int indexToSwap = size - i - 1;
      swap(arr, indexToSwap, i);
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
   int arr[]      = { 30, 10, 8, 2 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << maximumDifference(arr, size);
   return (0);
}
