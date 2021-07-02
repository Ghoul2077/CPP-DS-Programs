#include <iostream>
#include <math.h>
using namespace std;

// Takes O(n) time to search
int search(int *arr, int size, int searchItem) {
   for (int i = 0; i < size; i++) {
      if (arr[i] == searchItem) {
         return(i);
      }
   }
   return -1;
}

int main() {
   int  arr[] = { 1, 2, 3 };
   int  search_data;
   bool found = false;

   cout << "Enter Search Data : ";
   cin >> search_data;

   cout<<search(arr, sizeof(arr)/sizeof(arr[0]), search_data);

   return(0);
}
