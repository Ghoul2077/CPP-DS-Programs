#include <bits/stdc++.h>
using namespace std;

int firstIndexOf(int arr[], int size, int elem) {
   int index;

   for (index = 0; index < size; index++) {
      if (arr[index] == elem) {
         break;
      }
   }
   return (index);
}

int firstIndexOf2(int arr[], int size, int elem, int searchIndex = 0) {
   if (arr[searchIndex] == elem) {
      return (searchIndex);
   }

   if (searchIndex == size) {
      return (-1);
   }
   return (firstIndexOf2(arr, size, elem, ++searchIndex));
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5 };
   int elem  = 4;
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << firstIndexOf(arr, size, elem) << endl;
   cout << firstIndexOf2(arr, size, elem) << endl;
}
