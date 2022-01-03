#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << "  ";
   }
}

int min(int num1, int num2) {
   return (num1 > num2 ? num2 : num1);
}

int max(int num1, int num2) {
   return (num1 > num2 ? num1 : num2);
}

int maxElement(int *arr, int size, int exp = 0) {
   int maxVal = exp != 0 ? (arr[0] / exp) % 10 : arr[0];

   for (int i = 1; i < size; i++) {
      int val = exp != 0 ? (arr[i] / exp) % 10 : arr[i];
      maxVal = max(maxVal, val);
   }
   return (maxVal);
}

int minElement(int *arr, int size, int exp = 0) {
   int minVal = exp != 0 ? (arr[0] / exp) % 10 : arr[0];

   for (int i = 1; i < size; i++) {
      int val = exp != 0 ? (arr[i] / exp) % 10 : arr[i];
      minVal = min(minVal, val);
   }
   return (minVal);
}

void countSortHelperForRadixSort(int *arr, int size, int min, int max,
                                 int exp) {
   int  range = max - min + 1;
   int *count = new int[range], *output = new int[size];

   for (int i = 0; i < range; i++) {
      count[i] = 0;
   }

   for (int i = 0; i < size; i++) {
      int currVal    = (arr[i] / exp) % 10;
      int countIndex = currVal - min;
      count[countIndex]++;
   }

   for (int i = 1; i < range; i++) {
      count[i] = count[i - 1] + count[i];
   }

   for (int i = size - 1; i >= 0; i--) {
      int currVal    = (arr[i] / exp) % 10;
      int countIndex = currVal - min;
      output[count[countIndex] - 1] = arr[i];
      count[countIndex]--;
   }

   for (int i = 0; i < size; i++) {
      arr[i] = output[i];
   }

   delete[] count;
   delete[] output;
}

/**
 * @brief      Sorts a given array using counting sort routine under the hood.
 *             It applies count sort for every digits place individually and
 *             what we get is a sorted array in O(d * (n + b)) time complexity
 *             where d is max number of digit, n is size of array and b is the
 *             base. Space complexity is Q(n + b). It gives us the ability to
 *             have tradeoff between space and time as bigger base means lower
 *             time complexity but higher space complexity. This type of sorting
 *             fails when we have negative numbers.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void radixSort(int *arr, int size) {
   int maxVal = maxElement(arr, size);

   for (int exp = 1; (maxVal / exp) > 0; exp *= 10) {
      int currMaxVal = maxElement(arr, size, exp);
      int currMinVal = minElement(arr, size, exp);

      countSortHelperForRadixSort(arr, size, currMinVal, currMaxVal, exp);
   }
}

int main() {
   int arr[] = { 20, 50, 40, 10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   radixSort(arr, size);
   printArr(arr, size);

   return (0);
}
