#include <iostream>
using namespace std;

int positionsInArr(int arr[], int size, int elem) {
   int *output = new int[size];
   int counter = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] == elem) {
         output[counter] = i;
         counter++;
      }
   }
   return(counter);
}

int *positionsInArr2(int arr[], int size, int elem, int level = 0, int countIndex = 0) {
   if (level == size) {
      return(new int[countIndex]);
   }
   int *arr2 = 0;

   if (arr[level] == elem) {
      arr2             = positionsInArr2(arr, size, elem, level + 1, countIndex + 1);
      arr2[countIndex] = level;
   } else {
      arr2 = positionsInArr2(arr, size, elem, level + 1, countIndex);
   }
   return(arr2);
}

int main() {
   int arr[] = { 1, 2, 3, 4, 4, 5, 4 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int elem  = 4;

   cout << positionsInArr(arr, size, elem);
   int *p = positionsInArr2(arr, size, elem);
}
