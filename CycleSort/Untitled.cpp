#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << "  ";
   }
}

/**
 * @brief      Sorting using the concept that if we chain the sorting
 *             of elements then at sometime we are going to return
 *             to the index we started the chain in turn creating a
 *             cycle. Hence using the above method we traverse the
 *             array sorting in form of cycles. This takes O(n^2) time
 *             complexity but this takes least amount of swaps.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Number of swaps taken to sort the array
 */
int cycleSort(int *arr, int size) {
   int writes = 0;

   for (int i = 0; i < size - 1; i++) {
      int item     = arr[i];
      int position = i;

      for (int j = i + 1; j < size; j++) {
         if (arr[j] < item) {
            position++;
         }
      }

      if (i == position) {
         continue;
      }

      while (arr[position] == item) {
         position++;
      }
      swap(item, arr[position]);
      writes++;

      while (position != i) {
         position = i;

         for (int k = i + 1; k < size; k++) {
            if (arr[k] < item) {
               position++;
            }
         }

         while (arr[position] == item) {
            position++;
         }

         if (item != arr[position]) {
            swap(item, arr[position]);
            writes++;
         }
      }
   }

   return (writes);
}

int main() {
   int arr[] = { 20, 50, 40, 10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << cycleSort(arr, size) << endl;
   printArr(arr, size);

   return (0);
}
