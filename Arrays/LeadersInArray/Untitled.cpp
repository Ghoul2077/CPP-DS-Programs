#include <bits/stdc++.h>
using namespace std;

// Utility functions
void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

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
   int  biggest = INT_MIN;
   int *leaders = new int[size];
   int  counter = 0;

   for (int i = size - 1; i >= 0; i--) {
      if ((counter == 0) || (arr[i] > leaders[counter])) {
         leaders[counter++] = arr[i];
      }
   }

   reverse(leaders, leaders + counter);
   printArr(leaders, counter);
}

int main() {
   int arr[] = { 7, 10, 4, 10, 6, 5, 2 };

   // int       arr[] = { 0, 33, 33, 0, 30, 30, 1, 22, 69, 90, 88 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   // printLeadersNaive(arr, size);
   printLeaderOptimized(arr, size);
   return (0);
}
