#include <bits/stdc++.h>
using namespace std;

void deleteFromArrayIndex(int *arr, int size, int deleteIndex) {
   for (int i = deleteIndex; i < size; i++) {
      arr[i] = arr[i + 1];
   }
}

/**
 * @brief      Removes a duplicate from array in O(n^3) time complexity with
 *             O(n) auxillary space
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Size of new array
 */
int removeDuplicateNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         if (arr[i] == arr[j]) {
            deleteFromArrayIndex(arr, size--, j);
         }
      }
   }
   return (size);
}

/**
 * @brief      Removes duplicate from array in O(n) time complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Size of new array
 */
int removeDuplicate(int *arr, int size) {
   int *arrayPtr = new int[size];

   arrayPtr[0] = arr[0];
   int counter = 1;

   for (int i = 1; i < size; i++) {
      bool isPresent = false;

      for (int j = 0; j < counter; j++) {
         if (arr[i] == arrayPtr[j]) {
            isPresent = true;
            break;
         }
      }

      if (!isPresent) {
         arrayPtr[counter++] = arr[i];
      }
   }

   for (int i = 0; i < size; i++) {
      if (i < counter) {
         arr[i] = arrayPtr[i];
      } else {
         arr[i] = 0;
      }
   }
   return (counter);
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = { 16, 33, 33, 54, 30, 30, 1, 22, 69, 90, 88 };

   // int newSize = removeDuplicateNaive(arr, sizeof(arr) / sizeof(arr[0]));
   int newSize = removeDuplicate(arr, sizeof(arr) / sizeof(arr[0]));

   printArr(arr, newSize);
   return (0);
}
