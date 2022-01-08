#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; ++i) {
      cout << arr[i] << " ";
   }
}

/**
 * @brief      Counts the number of inversions in array in O(n^2) time complexity
 *             and Q(1) space complexity. Inversion is when comparing a[m] and
 *             a[n] if a[m] > a[n] with m < n then m & n is called inversion.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Number of inversions in array.
 */
int countInversionsInArrayNaive(int *arr, int size) {
   int count = 0;

   for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
         if (arr[i] > arr[j]) {
            cout << arr[i] << "," << arr[j] << endl;
            count++;
         }
      }
   }
   return (count);
}

int countInversionsInMergedArray(int *arr,
                                 int  start1,
                                 int  stop1,
                                 int  start2,
                                 int  stop2) {
   int  i = start1, j = start2;
   int  counter           = 0;
   int  size              = stop2 - start1 + 1;
   int  leftArraySize     = stop1 - start1 + 1;
   int *newArr            = new int[size];
   int  countOfInversions = 0;

   while (i <= stop1 && j <= stop2) {
      if (arr[i] <= arr[j]) {
         newArr[counter++] = arr[i++];
      } else {
         newArr[counter++] = arr[j++];
         int iteractionCountInLeftArray = i - start1;
         countOfInversions += (leftArraySize - iteractionCountInLeftArray);
      }
   }

   while (i <= stop1) {
      newArr[counter++] = arr[i++];
   }

   while (j <= stop2) {
      newArr[counter++] = arr[j++];
   }

   for (int i = start1; i <= stop2; i++) {
      arr[i] = newArr[i - start1];
   }

   delete[] newArr;
   return (countOfInversions);
}

/**
 * @brief      Counts the number of inversions in array in O(nlogn) time complexity
 *             and Q(n) space complexity. Inversion is when comparing a[m] and
 *             a[n] if a[m] > a[n] with m < n then m & n is called inversion.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Number of inversions in array.
 */
int countInversionsInArray(int *arr, int start, int stop) {
   int count = 0;

   if (start < stop) {
      int mid = (start + stop) / 2;
      count += countInversionsInArray(arr, start, mid);
      count += countInversionsInArray(arr, mid + 1, stop);
      count += countInversionsInMergedArray(arr, start, mid, mid + 1, stop);
   }

   return (count);
}

int main() {
   int arr[] = { 40, 30, 20, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << countInversionsInArrayNaive(arr, size);
   cout << countInversionsInArray(arr, 0, size);
   return (0);
}
