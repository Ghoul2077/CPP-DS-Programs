#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Reverses input array in O(n) time complexity and O(1) auxillary
 *             space
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void reverseArrayNaive(int *arr, int size) {
   for (int i = 0; i < size / 2; i++) {
      int temp = arr[i];
      arr[i]            = arr[size - i - 1];
      arr[size - i - 1] = temp;
   }
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = { 16, 34, 33, 54, 30, 10, 1, 22, 69, 90, 88 };

   reverseArrayNaive(arr, sizeof(arr) / sizeof(arr[0]));
   printArr(arr, sizeof(arr) / sizeof(arr[0]));
   return (0);
}
