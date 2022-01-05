#include <bits/stdc++.h>
using namespace std;

int lastIndexOf(int arr[], int size, int elem) {
   int index;

   for (index = size - 1; index > 0; index--) {
      if (arr[index] == elem) {
         break;
      }
   }
   return (index);
}

int lastIndexOfReccursive(int arr[], int size, int elem, int level = 1) {
   int searchIndex = size - level;

   if (arr[searchIndex] == elem) {
      return (searchIndex);
   } else if (searchIndex == -1) {
      return (false);
   } else {
      return (lastIndexOfReccursive(arr, size, elem, ++level));
   }
}

int main() {
   int arr[] = { 1, 2, 3, 4, 4, 5, 6, 9, 4, 5 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int elem  = 6;

   cout << lastIndexOf(arr, size, elem) << endl;
   cout << lastIndexOfReccursive(arr, size, elem);
}
