#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

// Utility functions
void reverseArray(int *arr, int size) {
   for (int i = 0; i < size / 2; i++) {
      int indexToSwap = size - i - 1;
      swap(arr[indexToSwap], arr[i]);
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

/**
 * @brief      Function to calculate maximum profit from buying and selling
 *             stocks with array being costs per day using Dynamic Programming
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  end    The end
 *
 * @return     Maximum Profit
 */
int maximizeProfitNaive(int *arr, int start, int end) {
   if (end <= start) {
      return(0);
   }

   int profit = 0;

   for (int i = start; i < end; i++) {
      for (int j = i + 1; j < end; j++) {
         int curr_profit = arr[j] - arr[i] +
                           maximizeProfitNaive(arr, start, i - 1) +
                           maximizeProfitNaive(arr, j + 1, end);

         if (curr_profit > profit) {
            profit = curr_profit;
         }
      }
   }


   return(profit);
}

/**
 * @brief      Function to calculate maximum profit from buying and selling
 *             stocks with array being costs per day using iteration in O(n) time
 *
 * @param      arr    The arr
 * @param[in]  start  The start
 * @param[in]  end    The end
 *
 * @return     Maximum Profit
 */
int maximizeProfit(int *arr, int size) {
   int profit = 0;

   for (int i = 1; i < size; i++) {
      if (arr[i] > arr[i - 1]) {
         profit += (arr[i] - arr[i - 1]);
      }
   }

   return(profit);
}

int main() {
   int arr[] = { 1, 5, 3, 8, 12 };
   // int       arr[] = { 0, 33, 33, 0, 30, 30, 1, 22, 69, 90, 88 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << maximizeProfitNaive(arr, 0, size);
   return(0);
}
