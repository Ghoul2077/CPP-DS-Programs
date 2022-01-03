#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds all elements with more than n by k ocuurance
 *             in O(n^2) time complexity and space complexity is
 *             Q(1).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     Deciding value for max number of occurances
 */
void findElementWithMoreThanNByKOcuuranceNaive(int *arr, int size, int k) {
   int minOccurance = size / k + 1;

   for (int i = 0; i < size; i++) {
      int  count             = 0;
      bool hasAppearedBefore = false;

      for (int j = 0; j < i; j++) {
         if (arr[j] == arr[i]) {
            hasAppearedBefore = true;
            break;
         }
      }

      if (!hasAppearedBefore) {
         for (int k = i; k < size; k++) {
            if (arr[i] == arr[k]) {
               count++;
            }
         }
      }

      if (count >= minOccurance) {
         cout << arr[i] << " ";
      }
   }
}

/**
 * @brief      Finds all elements with more than n by k ocuurance
 *             in O(nlogn) time complexity and space complexity is
 *             Q(1).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     Deciding value for max number of occurances
 */
void findElementWithMoreThanNByKOcuurance(int *arr, int size, int k) {
   sort(arr, arr + size);

   for (int i = 1; i < size; i++) {
      int count = 1;

      while (i < size && arr[i] == arr[i - 1]) {
         count++;
         i++;
      }

      if (count > size / k) {
         cout << arr[i] << " ";
      }
   }
}

/**
 * @brief      Finds all elements with more than n by k ocuurance
 *             in O(n) time complexity and space complexity is
 *             Q(n).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     Deciding value for max number of occurances
 */
void findElementWithMoreThanNByKOcuuranceOptimized(int *arr, int size, int k) {
   unordered_map<int, int> elementFrequency;
   int minOccurance = size / k + 1;

   for (int i = 0; i < size; i++) {
      if (elementFrequency.count(arr[i]) == 0) {
         elementFrequency.insert({ arr[i], 1 });
      } else {
         elementFrequency[arr[i]]++;
      }
   }

   for (auto i : elementFrequency) {
      if (i.second >= minOccurance) {
         cout << i.first << " ";
      }
   }
}

/**
 * @brief      Finds all elements with more than n by k ocuurance
 *             in O(n*k) time complexity and space complexity is
 *             O(k - 1). This is efficient solution as it will outperform the
 *             above given solution when k is very small compared to size of
 *             and it also has better space complexity. This approach is based
 *             on the fact that there can be at max (k - 1) elements with
 *             frequency greater than n / k.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     Deciding value for max number of occurances
 */
void findElementWithMoreThanNByKOcuuranceEfficient(int *arr, int size, int k) {
   unordered_map<int, int> elementFrequencyMap;

   for (int i = 0; i < size; i++) {
      if (elementFrequencyMap.count(arr[i]) == 1) {
         elementFrequencyMap[arr[i]]++;
      } else if (elementFrequencyMap.count(arr[i]) == 0) {
         elementFrequencyMap.insert({ arr[i], 1 });
      } else if (elementFrequencyMap.size() == (long long unsigned int)k - 1) {
         for (auto i : elementFrequencyMap) {
            i.second--;

            if (i.second == 0) {
               elementFrequencyMap.erase(i.first);
            }
         }
      }
   }

   for (auto i : elementFrequencyMap) {
      int count = 0;

      for (int j = 0; j < size; j++) {
         if (arr[j] == i.first) {
            count++;
         }
      }

      if (count > size / k) {
         cout << i.first << " ";
      }
   }
}

int main() {
   int arr[] = { 30, 10, 20, 30, 30, 40, 30, 40, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int k     = 2;

   findElementWithMoreThanNByKOcuuranceOptimized(arr, size, k);
   return (0);
}
