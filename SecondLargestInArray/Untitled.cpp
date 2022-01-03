#include <bits/stdc++.h>
using namespace std;

int findLargestLinear(int *arr, int size) {
   if (size == 1) {
      return (arr[0]);
   }
   int max = arr[0];

   for (int i = 1; i < size; i++) {
      if (arr[i] > max) {
         max = arr[i];
      }
   }
   return (max);
}

/**
 * @brief      Finds second largest in given array in O(n**2) complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     Second largest value from array
 */
int findSecondLargestNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int counter = 0;

      for (int j = 0; j < size; j++) {
         if (arr[j] > arr[i]) {
            counter++;
         }
      }

      if (counter == 1) {
         return (arr[i]);
      }
   }
   return (-1);
}

/**
 * @brief      Finds second largest in O(n) time complexity by making using of
 *             linear find largest
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     Second largest value from array
 */
int findSecondLargestLinear(int *arr, int size) {
   int largest       = findLargestLinear(arr, size);
   int secondLargest = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] != largest) {
         if (secondLargest == -1) {
            secondLargest = arr[i];
         } else if (arr[i] > secondLargest) {
            secondLargest = arr[i];
         }
      }
   }
   return (secondLargest);
}

/**
 * @brief      Finds a second largest in O(n) time complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Second largest value from array
 */
int findSecondLargest(int *arr, int size) {
   int secondLargest = -1, largest = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] > arr[largest]) {
         secondLargest = largest;
         largest       = i;
      } else if (arr[i] != arr[largest]) {
         if ((secondLargest == -1) || (arr[i] > arr[secondLargest])) {
            secondLargest = i;
         }
      }
   }
   return (arr[secondLargest]);
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = { 16, 34, 33, 54, 30, 10, 1, 22, 69, 90, 88 };

   cout << findSecondLargest(arr, sizeof(arr) / sizeof(arr[0]));
   return (0);
}
