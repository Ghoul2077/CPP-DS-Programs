#include <bits/stdc++.h>
using namespace std;

int max(int num1, int num2) {
   return (num1 > num2 ? num1 : num2);
}

int min(int num1, int num2) {
   return (num1 > num2 ? num2 : num1);
}

int medianOfSortedArray(int *arr, int size) {
   int mid = (size - 1) / 2;

   if (size % 2 == 0) {
      return ((arr[mid] + arr[mid + 1]) / 2);
   } else {
      return (arr[mid]);
   }
}

/**
 * @brief      Finds the median of 2 sorted arrays in Q(n1 + n2) time complexity
 *             and Q(n1 + n2) space complexity using merging technique from
 *             merge sort.
 *
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 *
 * @return     Median
 */
int medianOf2SortedArrays(int *arr1, int size1, int *arr2, int size2) {
   int *newArr = new int[size1 + size2];
   int  i = 0, j = 0;

   while (i < size1 && j < size2) {
      int index = i + j;

      if (arr1[i] < arr2[j]) {
         newArr[index] = arr1[i++];
      } else {
         newArr[index] = arr2[j++];
      }
   }

   while (j < size2) {
      newArr[i + j] = arr2[j];
      j++;
   }

   while (i < size1) {
      newArr[i + j] = arr1[i];
      i++;
   }

   return (medianOfSortedArray(newArr, size1 + size2));
}

/**
 * @brief      Finds the median of 2 sorted arrays in O(logn) time complexity
 *             and Q(1) space complexity using simultaneous binary search in the
 *             given 2 arrays
 *
 *
 * @param      arr1   The array 1
 * @param[in]  size1  The size of array 1
 * @param      arr2   The array 2
 * @param[in]  size2  The size of array 2
 *
 * @return     Median
 */
double medianOf2SortedArraysEfficient(int *arr1, int size1, int *arr2,
                                      int size2) {
   if (size1 > size2) {
      swap(arr1,  arr2);
      swap(size1, size2);
   }

   if (size1 == 0) {
      if (size2 % 2 == 0) {
         return ((arr2[size2 / 2] + arr2[size2 / 2 - 1]) / 2);
      } else {
         return (arr2[size2 / 2]);
      }
   }

   int low = 0, high = size1;
   int leftMax1, rightMin1, leftMax2, rightMin2;

   while (low <= high) {
      int mid1 = (low + high) / 2;
      int mid2 = (size1 + size2 + 1) / 2 - mid1;

      leftMax1  = mid1 == 0 ? INT_MIN : arr1[mid1 - 1];
      rightMin1 = mid1 == size1 ? INT_MAX :  arr1[mid1];
      leftMax2  = mid2 == 0 ? INT_MIN : arr2[mid2 - 1];
      rightMin2 = mid2 == size2 ? INT_MAX : arr2[mid2];

      if (rightMin1 < leftMax2) {
         low = mid1 + 1;
      } else if (leftMax1 > rightMin2) {
         high = mid1 - 1;
      } else {
         break;
      }
   }

   if ((size1 + size2) % 2 == 0) {
      return ((double)(max(leftMax1,
                           leftMax2) + min(rightMin1, rightMin2)) / 2);
   } else {
      return ((double)max(leftMax1, leftMax2));
   }
}

int main() {
   int arr1[] = { 1, 3 };
   int arr2[] = { 2 };
   int size1  = sizeof(arr1) / sizeof(arr1[0]);
   int size2  = sizeof(arr2) / sizeof(arr2[0]);

   cout << medianOf2SortedArraysEfficient(arr1, size1, arr2, size2) << endl;
   return (0);
}
