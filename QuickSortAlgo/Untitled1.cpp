#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
   }
   cout << endl;
}

int partitionArray(int arr[], int start, int end) {
   int *choosenElement = arr + start;
   int *leftPtr        = arr + start;
   int *rightPtr       = arr + end;
   int temp;

   while (leftPtr != rightPtr) {
      if (choosenElement == leftPtr) {
         if (*rightPtr < *choosenElement) {
            temp           = *rightPtr;
            *rightPtr      = *leftPtr;
            *leftPtr       = temp;
            choosenElement = rightPtr;
         } else {
            rightPtr--;
         }
      } else {
         if (*leftPtr > *choosenElement) {
            temp           = *leftPtr;
            *leftPtr       = *rightPtr;
            *rightPtr      = temp;
            choosenElement = leftPtr;
         } else {
            leftPtr++;
         }
      }
   }

   return(choosenElement - arr);
}

void quickSort(int arr[], int start, int end) {
   if (start < end) {
      int pos = partitionArray(arr, start, end);
      quickSort(arr, start, pos - 1);
      quickSort(arr, pos + 1, end);
   }
}

int main() {
   int arr[] = { 3, 4, 1, 5, 2 };

   quickSort(arr, 0, 4);
   printArr(arr, 5);
}
