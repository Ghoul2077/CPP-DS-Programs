#include <bits/stdc++.h>
using namespace std;

void printMap(unordered_map<int, int> *map) {
   for (auto i: *map) {
      cout << i.first << " : " << i.second << endl;
   }
}

/**
 * @brief      Find the frequency of each distinct element in a given array in
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void frequencyOfDistinctElementsNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int  count = 1;
      bool flag  = false;

      for (int j = i - 1; j >= 0; j--) {
         if (arr[j] == arr[i]) {
            flag = true;
            break;
         }
      }

      if (!flag) {
         for (int j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
               count++;
            }
         }
         cout << arr[i] << " : " << count << endl;
      }
   }
}

/**
 * @brief      Find the frequency of each distinct element in a given array in
 *             Q(n) time complexity and O(n) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     The map containing frequency of distinct elements.
 */
unordered_map<int, int>frequencyOfDistinctElements(int *arr, int size) {
   unordered_map<int, int> countMap;

   for (int i = 0; i < size; i++) {
      int currVal = arr[i];

      if (countMap.count(currVal) == 1) {
         countMap[currVal]++;
      }
      else {
         countMap[currVal] = 1;
      }
   }

   return (countMap);
}

int main() {
   int arr[] = { 15, 12, 13, 12, 13, 13, 18 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   // frequencyOfDistinctElementsNaive(arr, size);

   unordered_map<int, int> result = frequencyOfDistinctElements(arr, size);

   printMap(&result);

   return (0);
}
