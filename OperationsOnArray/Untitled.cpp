#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      cout << arr[i] << endl;
   }
}

void linearSearch(int arr[], int n, int x) {
   int i;

   for (i = 0; i < n; i++) {
      if (arr[i] == x) {
         cout << "Found element at index " << i << endl;
      }
   }

   if (i == n + 1) {
      cout << "Element Not Found in Array" << endl;
   }
}

void binarySearch(int arr[], int n, int x) {
   int start = 0, end = n, mid;

   while (start < end) {
      mid = (start + end) / 2;

      if (arr[mid] == x) {
         cout << "Found element at index " << mid << endl;
         break;
      } else if (x > arr[mid])   {
         start = mid + 1;
      } else  {
         end = mid - 1;
      }
   }

   if (start > end) {
      cout << "Element Not Found in Array" << endl;
   }
}

int insert(int arr[], int n, int x, int capacity, int pos) {
   if (n == capacity) {
      return (n);
   }
   int index = pos - 1;

   for (int i = n - 1; i > index; i--) {
      arr[i + 1] = arr[i];
   }
   arr[index] = x;
   return (n + 1);
}

int main() {
   int arr[] = { 1, 2, 3, 4, 5, 6 };

   linearSearch(arr, 6, 4);
   binarySearch(arr, 6, 4);

   // insert(arr, 6, 7, 7, 7);
   // printArr(arr, 7);
}
