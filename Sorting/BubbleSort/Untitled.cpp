#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

void bubbleSort(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      bool didSwap = false;

      for (int j = 0; j < size - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            didSwap = true;
         }
      }

      if (!didSwap) {
         break;
      }
   }
}

int main() {
   int arr[] = { 40, 30, 20, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   bubbleSort(arr, size);
   printArr(arr, size);
   return (0);
}
