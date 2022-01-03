#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << "  ";
   }
}

void insertionSort(int *arr, int size) {
   for (int i = 1; i < size; i++) {
      int curr = arr[i];
      int j    = i - 1;

      while (arr[j] > curr && j >= 0) {
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = curr;
   }
}

int main() {
   int arr[] = { 20, 50, 40, 10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   insertionSort(arr, size);
   printArr(arr, size);

   return (0);
}
