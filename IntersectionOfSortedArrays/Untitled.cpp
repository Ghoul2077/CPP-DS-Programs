#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

bool binarySearch(int *arr, int size, int val) {
   int low = 0, high = size - 1;

   while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] < val) {
         low = mid + 1;
      } else if (arr[mid] > val) {
         high = mid - 1;
      } else {
         return (true);
      }
   }
   return (false);
}

/**
 * @brief      Find the intersection between 2 sorted array using binary search
 *             in O(n^2) time complexity and Q(1) space complexity
 *
 * @param      arr1   The arr 1
 * @param[in]  size1  The size 1
 * @param      arr2   The arr 2
 * @param[in]  size2  The size 2
 */
void intersectionOfSortedArrayNaive(int *arr1, int size1, int *arr2,
                                    int size2) {
   for (int i = 0; i < size1; i++) {
      if ((i > 0) && (arr1[i] == arr1[i - 1])) {
         continue;
      }

      for (int j = 0; j < size2; j++) {
         if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            break;
         }
      }
   }
}

/**
 * @brief      Find the intersection between 2 sorted array using binary search
 *             in O(nlogn) time complexity and Q(smallerArraySize) space
 *             complexity
 *
 * @param      arr1   The arr 1
 * @param[in]  size1  The size 1
 * @param      arr2   The arr 2
 * @param[in]  size2  The size 2
 */
void intersectionOfSortedArray(int *arr1, int size1, int *arr2, int size2) {
   int *smallerArr       = size1 < size2 ? arr1 : arr2;
   int  smallerArrSize   = smallerArr == arr1 ? size1 : size2;
   int *greaterArr       = size1 > size2 ? arr1 : arr2;
   int  greaterArrSize   = greaterArr == arr1 ? size1 : size2;
   int *intersectedArray = new int[smallerArrSize];
   int  counter          = 0;

   for (int i = 0; i < smallerArrSize; i++) {
      if ((i > 0) &&) {
         bool isPresentInGreaterArr = binarySearch(greaterArr,
                                                   greaterArrSize,
                                                   smallerArr[i]);
      }
      bool isAlreadyPresentInIntersectedArr = binarySearch(intersectedArray,
                                                           counter,
                                                           smallerArr[i]);

      if (isPresentInGreaterArr && !isAlreadyPresentInIntersectedArr) {
         intersectedArray[counter++] = smallerArr[i];
      }
   }

   printArr(intersectedArray, counter);
}

/**
 * @brief      Find the intersection between 2 sorted array using binary search
 *             in O(n) time complexity and Q(1) space complexity using the
 *             algo from merge technique of merge sort.
 *
 * @param      arr1   The arr 1
 * @param[in]  size1  The size 1
 * @param      arr2   The arr 2
 * @param[in]  size2  The size 2
 */
void intersectionOfSortedArrayEfficient(int *arr1,
                                        int  size1,
                                        int *arr2,
                                        int  size2) {
   int i = 0, j = 0;

   while (i < size1 && j < size2) {
      if ((i > 0) && (arr[i] == arr[i - 1])) {
         i++;
         continue;
      }

      if (arr1[i] == arr2[j]) {
         cout << arr1[i] << " ";
         i++;
         j++;
      } else if (arr1[i] < arr2[j]) {
         i++;
      } else {
         j++;
      }
   }
}

int main() {
   int arr1[] = { 10, 20, 30, 40 };
   int arr2[] = { 2, 5, 10, 13, 30, 40 };
   int size1  = sizeof(arr1) / sizeof(arr1[0]);
   int size2  = sizeof(arr2) / sizeof(arr2[0]);

   intersectionOfSortedArrayEfficient(arr1, size1, arr2, size2);

   return (0);
}
