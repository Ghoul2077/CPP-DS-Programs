#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << "  ";
   }
}

int maxElement(int *arr, int size) {
   int maxVal = arr[0];

   for (int i = 1; i < size; i++) {
      maxVal = max(maxVal, arr[i]);
   }
   return (maxVal);
}

int minElement(int *arr, int size) {
   int minVal = arr[0];

   for (int i = 1; i < size; i++) {
      minVal = min(minVal, arr[i]);
   }
   return (minVal);
}

/**
 * @brief      Sorts the array by counting the occurances of elements. It's time
 *             time complexity is O(n + k) where k is the maximum value of range
 *             of the array so if k is bigger then it can perform worse than
 *             O(n^2) and O(k) space complexity. What makes this approach naive
 *             is that we are using indexes to finally replace values in array
 *             instead of original values (i.e assuming things to be sorted are
 *             numbers)
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  max   The maximum
 */
void countSortNaive(int *arr, int size, int max) {
   int *countArr = new int[max];

   for (int i = 0; i < max; i++) {
      countArr[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      countArr[arr[i]]++;
   }

   int index = 0;

   for (int i = 0; i < max; i++) {
      for (int j = 0; j < countArr[i]; j++) {
         arr[index++] = i;
      }
   }
}

/**
 * @brief      Sorts the array by counting the occurances of elements. It's time
 *             time complexity is O(n + k) where k is the maximum value of range
 *             of the array so if k is bigger then it can perform worse than
 *             O(n^2) and O(k) space complexity. The drawback of this approach
 *             is that it does not handle negative values.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  max   The maximum value of array + 1
 */
void countSort(int *arr, int size, int max) {
   int *countArr = new int[max];

   for (int i = 0; i < max; i++) {
      countArr[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      countArr[arr[i]]++;
   }

   for (int i = 1; i < max; i++) {
      countArr[i] = countArr[i] + countArr[i - 1];
   }

   int *outputArr = new int[size];

   for (int i = size - 1; i >= 0; i--) {
      outputArr[countArr[arr[i]] - 1] = arr[i];
      countArr[arr[i]]--;
   }

   for (int i = 0; i < size; i++) {
      arr[i] = outputArr[i];
   }

   delete[] outputArr;
   delete[] countArr;
}

/**
 * @brief      Sorts the array by counting the occurances of elements. It's time
 *             time complexity is O(n + k) where k is the maximum value of range
 *             of the array so if k is bigger then it can perform worse than
 *             O(n^2) and O(k) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  max   The maximum value of array
 */
void countSortOptimized(int *arr, int size, int min, int max) {
   int  range = max - min + 1;
   int *count = new int[range], *output = new int[size];

   for (int i = 0; i < range; i++) {
      count[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      count[arr[i] - min]++;
   }

   for (int i = 1; i < range; i++) {
      count[i] = count[i - 1] + count[i];
   }

   for (int i = size - 1; i >= 0; i--) {
      int val = arr[i] - min;
      output[count[val] - 1] = arr[i];
      count[val]--;
   }

   for (int i = 0; i < size; i++) {
      arr[i] = output[i];
   }

   delete[] output;
   delete[] count;
}

int main() {
   int arr[] = { 20, 50, 40, -10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int max   = maxElement(arr, size);
   int min   = minElement(arr, size);

   // countSort(arr, size, max + 1);
   countSortOptimized(arr, size, min, max);
   printArr(arr, size);

   return (0);
}
