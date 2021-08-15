#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

void insertSort(int *arr, int size) {
   for (int i = 1; i < size; i++) {
      int curr  = arr[i];
      int index = i - 1;
      while (arr[index] > curr && index >= 0) {
         arr[index + 1] = arr[index];
         index--;
      }
      arr[index + 1] = curr;
   }
}

int main() {
   int arr[] = { 40, 30, 20, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   insertSort(arr, size);
   printArr(arr, size);
   return(0);
}
