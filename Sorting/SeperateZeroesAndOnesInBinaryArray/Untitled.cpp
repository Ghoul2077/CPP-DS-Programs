#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

/**
 * @brief      Segregate zeroes and ones in O(nlogn) time complexity and Q(1)
 *             space complexity by using sorting.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void segregateOnesAndZeroesNaive(int *arr, int size) {
   sort(arr, arr + size);
}

/**
 * @brief      Segregates zeroes and ones in an array using two pointer approach
 *             in O(n) time complexity and Q(1) space complexity.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void segregateOnesAndZeroes(int *arr, int size) {
   int ptr1 = 0, ptr2 = size - 1;

   while (ptr1 < ptr2) {
      if (arr[ptr1] == 1) {
         swap(arr[ptr1], arr[ptr2]);
         ptr2--;
      } else {
         ptr1++;
      }
   }
}

int main() {
   int arr[] = { 0, 0, 1, 1, 0, 0, 0, 1 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   segregateOnesAndZeroes(arr, size);
   printArr(arr, size);

   return (0);
}
