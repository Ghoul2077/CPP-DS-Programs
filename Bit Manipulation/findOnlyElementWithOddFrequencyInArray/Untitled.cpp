#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds the only element with odd number of occurances in a given
 *             array of integers. It is assumed that there is only single
 *             element with odd frequency. It's time complexity is O(n^2) and
 *             it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Element with odd frequency
 */
int findTheOnlyOddOccuringElementNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int count = 0;

      for (int j = 0; j < size; j++) {
         if (arr[j] == arr[i]) {
            count++;
         }
      }

      if (count % 2 != 0) {
         return (arr[i]);
      }
   }
   return (-1);
}

/**
 * @brief      Finds the only element with odd number of occurances in a given
 *             array of integers. It is assumed that there is only single
 *             element with odd frequency. It's time complexity is O(n) and it's
 *             space complexity is O(n). In this method we use hashing to store
 *             frequencies and then find the one with odd frequency.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Element with odd frequency
 */
int findTheOnlyOddOccuringElement(int *arr, int size) {
   unordered_map<int, int> elementToFrequencyMap;

   for (int i = 0; i < size; i++) {
      elementToFrequencyMap[arr[i]]++;
   }

   for (auto i : elementToFrequencyMap) {
      if (i.second % 2 != 0) {
         return (i.first);
      }
   }
   return (-1);
}

/**
 * @brief      Finds the only element with odd number of occurances in a given
 *             array of integers. It is assumed that there is only single
 *             element with odd frequency. It's time complexity is O(n) and it's
 *             space complexity is O(1). The idea behind this method is that XOR
 *             between the same number gives 0 and XOR of any number with 0
 *             is the number itself, so by this rule all even occurances will
 *             cancel out giving 0 and only the odd occuring element will be
 *             left.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Element with odd frequency
 */
int findTheOnlyOddOccuringElementOptimized(int *arr, int size) {
   int xorResult = arr[0];

   for (int i = 1; i < size; i++) {
      xorResult ^= arr[i];
   }
   return (xorResult);
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
      cout << findTheOnlyOddOccuringElement(arr, size);
      cout << endl;
   }
   return (0);
}
