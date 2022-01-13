#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

int findIndexOfMax(int *arr, int size) {
   int max = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] > arr[max]) {
         max = i;
      }
   }
   return (max);
}

void selectionSort(int *arr, int size) {
   for (int i = 0; i < size - 1; i++) {
      int max       = findIndexOfMax(arr, size - i);
      int swapIndex = size - i - 1;
      swap(arr[max], arr[swapIndex]);
   }
}

int main() {
   int arr[] = { 40, 30, 20, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   selectionSort(arr, size);
   printArr(arr, size);
   return (0);
}
