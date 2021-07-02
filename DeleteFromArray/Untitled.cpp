#include <iostream>
#include <math.h>
using namespace std;

// Has time complexity of O(n)
void deleteFromArrayIndex(int *arr, int size, int deleteIndex) {
   for (int i = deleteIndex; i < size; i++) {
      arr[i] = arr[i + 1];
   }
}

int deleteFromArray(int *arr, int size, int deleteItem) {
   int i;
   for (i = 0; i < size; i++) {
      if (arr[i] == deleteItem) {
         break;
      }
   }
   if (i == size) {
      return(size);
   }
   for (i; i < size; i++) {
      arr[i] = arr[i + 1];
   }
   return(size - 1);
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << endl;
   }
}

int main() {
   int arr[] = { 1, 2, 3 };
   int delete_val;

   cout << "Enter index to delete : ";
   cin >> delete_val;

   deleteFromArray(arr, sizeof(arr) / sizeof(arr[0]), delete_val);
   printArr(arr, sizeof(arr) / sizeof(arr[0]) - 1);

   return(0);
}
