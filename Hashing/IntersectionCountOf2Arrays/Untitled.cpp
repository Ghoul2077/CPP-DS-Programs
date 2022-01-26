#include <bits/stdc++.h>
using namespace std;

unordered_set<int>* findDistinctElements(int *arr, int size) {
   unordered_set<int> *result = new unordered_set<int>;

   for (int i = 0; i < size; i++) {
      if (result->count(arr[i]) == 0) {
         result->insert(arr[i]);
      }
   }

   return (result);
}

/**
 * @brief      Finds a number of intersections between 2 given arrays in
 *             O(n1*n2) time complexity and Q(1) space complexity.
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 *
 * @return     Number of intersections
 */
int findNumberOfIntersectionsNaive(int *arr1, int size1, int *arr2, int size2) {
   int count = 0;

   for (int i = 0; i < size1; i++) {
      bool hasAppearedBefore = false;

      for (int j = i - 1; j >= 0; j--) {
         if (arr1[i] == arr1[j]) {
            hasAppearedBefore = true;
         }
      }

      if (hasAppearedBefore) {
         continue;
      }

      for (int j = 0; j < size2; j++) {
         if (arr1[i] == arr2[j]) {
            count++;
            break;
         }
      }
   }

   return (count);
}

/**
 * @brief      Finds a number of intersections between 2 given arrays in
 *             O(n1 + n2) time complexity but with 3 traversals and Q(n1 + n2)
 *             space complexity.
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 *
 * @return     Number of intersections
 */
int findNumberOfIntersections(int *arr1, int size1, int *arr2, int size2) {
   unordered_set<int> *distinctElements1 = findDistinctElements(arr1, size1);
   unordered_set<int> *distinctElements2 = findDistinctElements(arr2, size2);
   int count                             = 0;

   for (auto i : *distinctElements1) {
      if (distinctElements2->count(i) == 1) {
         count++;
      }
   }

   return (count);
}

/**
 * @brief      Finds a number of intersections between 2 given arrays in
 *             O(n1 + n2) time complexity but with 2 traversals and Q(n1 + n2)
 *             space complexity.
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 *
 * @return     Number of intersections
 */
int findNumberOfIntersectionsOptimized(int *arr1,
                                       int  size1,
                                       int *arr2,
                                       int  size2) {
   unordered_set<int> distinctElements1(arr1, arr1 + size1);
   int count = 0;

   for (int i = 0; i < size2; i++) {
      if (distinctElements1.count(arr2[i]) == 1) {
         distinctElements1.erase(arr2[i]);
         count++;
      }
   }

   return (count);
}

int main() {
   int arr1[] = { 10, 15, 20, 5, 30 };
   int size1  = sizeof(arr1) / sizeof(arr1[0]);

   int arr2[] = { 30, 5, 30, 80 };
   int size2  = sizeof(arr2) / sizeof(arr2[0]);

   cout << findNumberOfIntersectionsOptimized(arr1, size1, arr2, size2);
   return (0);
}
