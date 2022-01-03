#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Counts the number of distinct elements in windows of k size taken
 *             one at a time. it's time complexity is O((n - k) * k * k) where
 *             n is size of array and k is window size. Space complexity is Q(1)
 *
 * @param      arr         the arr
 * @param[in]  size        the size
 * @param[in]  windowsize  the window size
 */
void countOfDistinctElementsInWindowsOfKSizeNaive(int *arr, int size,
                                                  int windowSize) {
   for (int i = 0; i <= size - windowSize; i++) {
      int countDistinct = 0;

      for (int j = i; j < i + windowSize; j++) {
         bool hasAppearedBefore = false;

         for (int k = i; k < j; k++) {
            if (arr[k] == arr[j]) {
               hasAppearedBefore = true;
               break;
            }
         }

         if (!hasAppearedBefore) {
            countDistinct++;
         }
      }
      cout << countDistinct << " ";
   }
}

/**
 * @brief      Counts the number of distinct elements in windows of k size taken
 *             one at a time. it's time complexity is Q(n) where n is the size
 *             of array and k is window size. Space complexity is O(k)
 *
 * @param      arr         the arr
 * @param[in]  size        the size
 * @param[in]  windowsize  the window size
 */
void countOfDistinctElementsInWindowsOfKSize(int *arr, int size,
                                             int windowSize) {
   unordered_map<int, int> distinctElements;

   for (int i = 0; i < windowSize; i++) {
      if (distinctElements.count(arr[i]) == 0) {
         distinctElements.insert({ arr[i], 1 });
      } else {
         distinctElements[arr[i]]++;
      }
   }

   cout << distinctElements.size() << "  ";

   for (int i = windowSize; i < size; i++) {
      int startingIndex = i - windowSize;

      if (distinctElements[arr[startingIndex]] == 1) {
         distinctElements.erase(arr[startingIndex]);
      } else {
         distinctElements[arr[startingIndex]]--;
      }

      if (distinctElements.count(arr[i]) == 0) {
         distinctElements.insert({ arr[i], 1 });
      } else {
         distinctElements[arr[i]]++;
      }
      cout << distinctElements.size() << "  ";
   }
}

int main() {
   int arr[]      = { 10, 10, 10, 10 };
   int size       = sizeof(arr) / sizeof(arr[0]);
   int windowSize = 3;

   countOfDistinctElementsInWindowsOfKSizeNaive(arr, size, windowSize);
   return (0);
}
