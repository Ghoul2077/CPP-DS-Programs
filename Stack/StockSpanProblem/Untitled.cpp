#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

/**
 * @brief      Finds a stock span of given stock prices. Stock span for index i
 *             is given as the number of elements less than equal to its left
 *             until the first biggest element. It's time complexity is O(n^2)
 *             and space complexity is O(n).
 *
 * @param      stockPrices  The stock prices
 * @param[in]  size         The size
 *
 * @return     Array with stock span of each index
 */
int* findStockSpanNaive(int *stockPrices, int size) {
   int *arr = new int[size];

   for (int i = 0; i < size; i++) {
      int count = 1;

      for (int j = i - 1; j >= 0 && stockPrices[j] <= stockPrices[i]; j--) {
         count++;
      }
      arr[i] = count;
   }

   return (arr);
}

/**
 * @brief      Finds a stock span of given stock prices. Stock span for index i
 *             is given as the number of elements less than equal to its left
 *             until the first biggest element. This method uses stack to find
 *             previous greater element index and using that index computes the
 *             span for given index, It's time complexity is O(n) and it's space
 *             complexity is O(n).
 *
 * @param      stockPrices  The stock prices
 * @param[in]  size         The size
 *
 * @return     Array with stock span of each index
 */
int* findStockSpan(int *stockPrices, int size) {
   int *arr = new int[size];
   stack<int> firstBiggestElementToLeft;

   firstBiggestElementToLeft.push(0);
   arr[0] = 1;

   for (int i = 1; i < size; i++) {
      while (!firstBiggestElementToLeft.empty() &&
             stockPrices[firstBiggestElementToLeft.top()] <= stockPrices[i]) {
         firstBiggestElementToLeft.pop();
      }
      int span = firstBiggestElementToLeft.empty() ?
                 i + 1 : i - firstBiggestElementToLeft.top();
      arr[i] = span;
      firstBiggestElementToLeft.push(i);
   }

   return (arr);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }

      int *stockSpan = findStockSpan(arr, size);
      printArr(stockSpan, size);
      cout << endl;
   }
   return (0);
}
