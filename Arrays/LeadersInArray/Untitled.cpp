#include <bits/stdc++.h>
using namespace std;

// Utility functions
void printArr(int *arr,
              int  size);
void swap(int *arr,
          int  index1,
          int  index2);
void reverseArray(int *arr,
                  int  size);

/**
 * @brief      Prints leaders in an array in O(n^2) time complexity and Q(1)
 *             auxillary space.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void printLeadersNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      bool flag = true;

      for (int j = i + 1; j < size; j++) {
         if (arr[i] < arr[j]) {
            flag = false;
            break;
         }
      }

      if (flag) {
         cout << arr[i] << " ";
      }
   }
}

/**
 * @brief      Prints leaders in O(n) time complexity and Q(1) auxillary space.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void printLeaderOptimized(int *arr, int size) {
   // simplified version of uncommmented code below, it prints leaders in
   // reverse order unlike the uncommented one

   // int biggest = INT_MIN;

   // for (int i = size - 1; i >= 0; i--) {
   //    if (arr[i] > biggest) {
   //       cout<<arr[i]<<" ";
   //       biggest = arr[i];
   //    }
   // }

   int  biggest = INT_MIN;
   int *leaders = new int[size];
   int  counter = 0;

   for (int i = size - 1; i >= 0; i--) {
      if ((counter == 0) || (arr[i] > leaders[counter])) {
         leaders[counter++] = arr[i];
      }
   }

   reverseArray(leaders, counter);
   printArr(leaders, counter);
}

void reverseArray(int *arr, int size) {
   for (int i = 0; i < size / 2; i++) {
      int indexToSwap = size - i - 1;
      swap(arr, indexToSwap, i);
   }
}

void swap(int *arr, int index1, int index2) {
   int temp = arr[index1];

   arr[index1] = arr[index2];
   arr[index2] = temp;
}

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = { 7, 10, 4, 10, 6, 5, 2 };

   // int       arr[] = { 0, 33, 33, 0, 30, 30, 1, 22, 69, 90, 88 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   // printLeadersNaive(arr, size);
   printLeaderOptimized(arr, size);
   return (0);
}
