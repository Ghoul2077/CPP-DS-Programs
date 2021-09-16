#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printMap(unordered_map<int, int> *map) {
   for (auto i: *map) {
      cout << i.first << " : " << i.second << endl;
   }
}

/**
 * @brief      Finds a count of distinct elements in a given array in O(n^2)
 *             time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     The count of distinct elements
 */
int findCountOfDistinctNaive(int *arr, int size) {
   int count = 0;

   for (int i = 0; i < size; i++) {
      bool flag = false;

      for (int j = i - 1; j >= 0; j--) {
         if (arr[j] == arr[i]) {
            flag = true;
         }
      }

      if (!flag) {
         count++;
      }
   }

   return (count);
}

/**
 * @brief      Finds a count of distinct elements in a given array in O(n)
 *             time complexity and Q(n) space complexity using hash map.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Hash map containing the count of each distinct elements
 */
int findCountOfDistinct(int *arr, int size) {
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

   return (countMap.size());
}

/**
 * @brief      Finds a count of distinct elements in a given array in O(n) time
 *             complexity and O(n) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Number of distinct elements
 */
int findCountOfDistinctOptimized(int *arr, int size) {
   unordered_set<int> result(arr, arr + size);

   return (result.size());
}

int main() {
   int arr[] = { 15, 12, 13, 12, 13, 13, 18 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << findCountOfDistinct(arr, size);
   cout << findCountOfDistinctNaive(arr, size);
   cout << findCountOfDistinctOptimized(arr, size);
}
