#include <iostream>
using namespace std;

void bubbleSort(int *a, int n) {
   int j, k, temp;

   for (k = 1; k < n; k++) {
      for (j = 0; j < n - k; j++) {
         if (a[j] > a[j + 1]) {
            temp     = a[j];
            a[j]     = a[j + 1];
            a[j + 1] = temp;
         }
      }
   }
}

void insertionSort(int *a, int n) {
   int i, j, temp;

   for (i = 1; i <= n; i++) {
      temp = a[i];
      j    = i - 1;
      while (j >= 0 && a[j] > a[i]) {
         a[j + 1] = a[j];
         j--;
      }
      a[j + 1] = temp;
   }
}

int main() {
   int input[100], arraySize, toFind;

   cout << "Enter Number of Elements : ";
   cin >> arraySize;
   for (int i = 0; i < arraySize; i++) {
      cout << "Element " << i + 1 << " : ";
      cin >> input[i];
   }
   insertionSort(input, arraySize);
   cout << "Sorted Array is : ";
   for (int i = 0; i < arraySize; i++) {
      cout << input[i] << " ";
   }
}
