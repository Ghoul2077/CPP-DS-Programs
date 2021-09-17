#include <iostream>
#include <unordered_set>
using namespace std;

void printSet(unordered_set<int> *set) {
   for (auto i : *set) {
      cout << i << "  ";
   }
   cout << endl;
}

/**
 * @brief      Finds a distinct of 2 given arrays combined in
 *             O(n1^2 + n2 * (n1 + n2)) time complexity and Q(n1 + n2) space
 *             complexity.
 *
 * @param      arr1   The arr 1
 * @param[in]  size1  The size 1
 * @param      arr2   The arr 2
 * @param[in]  size2  The size 2
 *
 * @return     The count of total distinct elements in 2 arrays combined
 */
int findDistinctOf2ArrayNaive(int *arr1, int size1, int *arr2, int size2) {
   int *distinctElements = new int[size1 + size2];
   int  count            = 0;

   for (int i = 0; i < size1; i++) {
      bool isAlreadyPresent = false;

      for (int j = 0; j < count; j++) {
         if (arr1[i] == distinctElements[j]) {
            isAlreadyPresent = true;
            break;
         }
      }

      if (!isAlreadyPresent) {
         distinctElements[count++] = arr1[i];
      }
   }

   for (int i = 0; i < size1; i++) {
      bool isAlreadyPresent = false;

      for (int j = 0; j < count; j++) {
         if (arr2[i] == distinctElements[j]) {
            isAlreadyPresent = true;
            break;
         }
      }

      if (!isAlreadyPresent) {
         distinctElements[count++] = arr2[i];
      }
   }

   return (count);
}

/**
 * @brief      Finds a distinct of 2 given arrays combined in Q(n1 + n2)
 *             time complexity and O(n1 + n2) space complexity.
 *
 * @param      arr1   The arr 1
 * @param[in]  size1  The size 1
 * @param      arr2   The arr 2
 * @param[in]  size2  The size 2
 *
 * @return     The count of total distinct elements in 2 arrays combined
 */
int findDistinctOf2Array(int *arr1, int size1, int *arr2, int size2) {
   unordered_set<int> result;

   for (int i = 0; i < size1; i++) {
      result.insert(arr1[i]);
   }

   for (int i = 0; i < size2; i++) {
      result.insert(arr2[i]);
   }

   return (result.size());
}

int main() {
   int arr1[] = { 10, 15, 20, 5, 30 };
   int size1  = sizeof(arr1) / sizeof(arr1[0]);

   int arr2[] = { 30, 5, 30, 80 };
   int size2  = sizeof(arr2) / sizeof(arr2[0]);

   cout << findDistinctOf2ArrayNaive(arr1, size1, arr2, size2);
   return (0);
}
