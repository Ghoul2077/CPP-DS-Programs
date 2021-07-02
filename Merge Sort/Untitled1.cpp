#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
   }
   cout << endl;
}

void merge(int arr[], int start1, int end1, int start2, int end2) {
   int i = start1;
   int j = start2;
   int k;
   int counter   = 0;
   int size      = end2 - start1 + 1;
   int *finalArr = new int[size];

   while (i <= end1 && j <= end2) {
      if (arr[i] < arr[j]) {
         finalArr[counter++] = arr[i++];
      } else {
         finalArr[counter++] = arr[j++];
      }
   }

   if (i <= end1) {
      while (i <= end1) {
         finalArr[counter++] = arr[i++];
      }
   } else {
      while (j <= end2) {
         finalArr[counter++] = arr[j++];
      }
   }

   for (int m = start1; m < start1 + size; m++) {
      arr[m] = finalArr[m - start1];
   }

   delete[] finalArr;
}

void mergeSort(int arr[], int start, int end) {
   if (start < end) {
      int mid = (start + end) / 2;
      mergeSort(arr, start, mid);
      mergeSort(arr, mid + 1, end);
      merge(arr, start, mid, mid + 1, end);
   }
}

int main() {
   int arr[] = { 5, 4, 3, 2, 1 };

   mergeSort(arr, 0, 4);
   printArr(arr, 5);
}
