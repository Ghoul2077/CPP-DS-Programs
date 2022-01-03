#include <bits/stdc++.h>
using namespace std;

// Has time complexity of O(n)
int insert(int *arr, int size, int insertItem, int insertIndex, int capacity) {
   if ((insertIndex >= capacity) || (size == capacity)) {
      return (size);
   }

   for (int i = size - 1; i >= insertIndex; i--) {
      arr[i + 1] = arr[i];
   }
   arr[insertIndex] = insertItem;
   return (size + 1);
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << endl;
   }
}

int main() {
   int arr[10] = { 1, 2, 3 };
   int insert_data;
   int insert_at;

   cout << "Enter data to insert : ";
   cin >> insert_data;
   cout << "Enter index to insert at : ";
   cin >> insert_at;

   insert(arr, 3, insert_data, insert_at, sizeof(arr) / sizeof(arr[0]));
   printArr(arr, 4);

   return (0);
}
