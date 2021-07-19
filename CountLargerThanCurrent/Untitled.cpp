#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

int min(int num1, int num2) {
   return num1 > num2 ? num2 : num1;
}

int* countLargerThanCurrNaive(int *arr, int size) {
   int *counts = new int[size];
   for(int i = 0; i < size; i++) {
      int count = 0;
      for(int j = 0; j < i; j++) {
         if(arr[j] > arr[i]) count++;
      }
      counts[i] = count;
   }

   return counts;
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int       arr[] = { 1, 8, 30, -5, 20, 7, 3 };
   int       sum   = 30;
   const int size  = sizeof(arr) / sizeof(arr[0]);

   int* counts = countLargerThanCurrNaive(arr, size);
   printArr(counts, size);
   return(0);
}
