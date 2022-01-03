#include <bits/stdc++.h>
using namespace std;

// Utility functions
int max(int num1, int num2) {
   return (num1 > num2 ? num1 : num2);
}

int min(int num1, int num2) {
   return (num1 > num2 ? num2 : num1);
}

/**
 * @brief      Calculates the water quantity in O(n^2) time compelxity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     The water quantity naive.
 */
int calculateWaterQuantityNaive(int *arr, int size) {
   int res = 0;

   for (int i = 0; i < size - 1; i++) {
      int lmax = arr[i], rmax = arr[i];

      for (int j = 0; j < i; j++) {
         lmax = max(lmax, arr[j]);
      }

      for (int j = i + 1; j < size; j++) {
         rmax = max(rmax, arr[j]);
      }
      res += (min(lmax, rmax) - arr[i]);
   }
   return (res);
}

/**
 * @brief      Calculates the water quantity in O(n) time complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     The water quantity.
 */
int calculateWaterQuantity(int *arr, int size) {
   int  res = 0;
   int *lmax = new int[size], *rmax = new int[size];

   lmax[0] = arr[0];

   for (int i = 1; i < size; i++) {
      lmax[i] = max(arr[i], lmax[i - 1]);
   }

   rmax[size - 1] = arr[size - 1];

   for (int i = size - 2; i >= 0; i--) {
      rmax[i] = max(arr[i], rmax[i + 1]);
   }

   for (int i = 1; i < size - 1; i++) {
      res += (min(lmax[i], rmax[i]) - arr[i]);
   }

   return (res);
}

int main() {
   int arr[]      = { 2, 0, 2 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << calculateWaterQuantity(arr, size);
   return (0);
}
