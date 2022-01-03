#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
   }
   cout << endl;
}

int findMaxInArray(int *arr, int size) {
   int max = arr[0];

   for (int i = 1; i < size; i++) {
      if (arr[i] > max) {
         max = arr[i];
      }
   }
   return (max);
}

void merge(int arr[], int start1, int end1, int start2, int end2) {
   int  i = start1;
   int  j = start2;
   int  k;
   int  counter  = 0;
   int  size     = end2 - start1 + 1;
   int *finalArr = new int[size];

   while (i <= end1 && j <= end2) {
      if (arr[i] <= arr[j]) {
         finalArr[counter++] = arr[i++];
      } else {
         finalArr[counter++] = arr[j++];
      }
   }

   while (i <= end1) {
      finalArr[counter++] = arr[i++];
   }

   while (j <= end2) {
      finalArr[counter++] = arr[j++];
   }

   for (int m = start1; m < start1 + size; m++) {
      arr[m] = finalArr[m - start1];
   }

   delete[] finalArr;
}

void mergeSort(int arr[], int start, int end) {
   if (start < end) {
      int mid = (start + end) / 2;
      mergeSort(arr, start,   mid);
      mergeSort(arr, mid + 1, end);
      merge(arr, start, mid, mid + 1, end);
   }
}

/**
 * @brief      Finds the repeating number in a given array where conditions are
 *             that array will contain every number of 0 to max of array and out
 *             of those one number will repeat n times. The following algo takes
 *             O(n^2) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     The repeating element
 */
int findRepeatingNumberSuperNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         if (arr[i] == arr[j]) {
            return (arr[i]);
         }
      }
   }
   return (-1);
}

/**
 * @brief      Finds the repeating number in a given array where conditions are
 *             that array will contain every number of 0 to max of array and out
 *             of those one number will repeat n times. The following algo takes
 *             O(logn) time complexity and Q(n) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     The repeating element
 */
int findRepeatingNumberNaive(int *arr, int size) {
   mergeSort(arr, 0, size);

   for (int i = 1; i < size; i++) {
      if (arr[i] == arr[i - 1]) {
         return (arr[i]);
      }
   }
   return (-1);
}

/**
 * @brief      Finds the repeating number in a given array where conditions are
 *             that array will contain every number of 0 to max of array and out
 *             of those one number will repeat n times. The following algo takes
 *             O(n) time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     The repeating element
 */
int findRepeatingNumber(int *arr, int size) {
   int max                    = findMaxInArray(arr, size);
   int sumOfNonRepeatingArray = (max * (max + 1)) / 2;
   int sumOfGivenArray        = 0;

   for (int i = 0; i < size; i++) {
      sumOfGivenArray += arr[i];
   }

   int diff                         = sumOfGivenArray - sumOfNonRepeatingArray;
   int numberOfTimesElementRepeated = size - max - 1;
   int element                      = diff / numberOfTimesElementRepeated;

   return (element);
}

/**
 * @brief      Finds the repeating number in a given array where conditions are
 *             that array will contain every number of 0 to max of array and out
 *             of those one number will repeat n times. The following algo takes
 *             O(n) time complexity and Q(1) space complexity using hare and
 *             tortoise method.
 *
 * @param      arr   The arr
 * @param[in]  size  The size of array
 *
 * @return     The repeating element
 */
int findRepeatingNumber2(int *arr, int size) {
   int slow = arr[0] + 1, fast = arr[0] + 1;

   do {
      slow = arr[slow] + 1;
      fast = arr[arr[fast] + 1] + 1;
   } while (slow != fast);

   slow = arr[0] + 1;

   while (slow != fast) {
      slow = arr[slow] + 1;
      fast = arr[fast] + 1;
   }
   return (slow - 1);
}

int main() {
   int arr[] = { 0, 1, 9, 8, 5, 4, 6, 4, 7, 2, 4, 4, 4, 3 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << findRepeatingNumber2(arr, size);
   return (0);
}
