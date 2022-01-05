#include <bits/stdc++.h>
using namespace std;

int firstIndexOfIterative(int arr[], int size, int elem) {
   int index;

   for (index = 0; index < size; index++) {
      if (arr[index] == elem) {
         break;
      }
   }
   return (index);
}

int firstIndexOfReccursive(int arr[], int size, int elem, int searchIndex = 0) {
   if (arr[searchIndex] == elem) {
      return (searchIndex);
   }

   if (searchIndex == size) {
      return (-1);
   }
   return (firstIndexOfReccursive(arr, size, elem, ++searchIndex));
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5 };
   int elem  = 4;
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << firstIndexOfIterative(arr, size, elem) << endl;
   cout << firstIndexOfReccursive(arr, size, elem) << endl;
}
