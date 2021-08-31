#include <iostream>
#include <math.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

void swap(int&num1, int&num2) {
   int temp = num1;

   num1 = num2;
   num2 = temp;
}

/**
 * @brief      Partition given array into 3 parts based on 2 given pivot indexes
 *             first part contains number less than smaller pivot, 2nd part
 *             contains numbers greater than smaller and greater than larger
 *             pivot and the 3rd and last part contains numbers greater than the
 *             larger pivot. And this algo does this in O(4n) time complexity and
 *             Q(n) space complexity
 *             
 * @param      arr          The arr
 * @param[in]  size         The size
 * @param[in]  pivotIndex1  The pivot index 1
 * @param[in]  pivotIndex2  The pivot index 2
 */
void partitionAroundThreePivotsNaive(int *arr, int size, int pivotIndex1, int pivotIndex2) {
   int pivot1 = arr[pivotIndex1], pivot2 = arr[pivotIndex2];

   if (pivot1 > pivot2) {
      swap(pivot1, pivot2);
   }

   int *newArr = new int[size];
   int counter = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] < pivot1) {
         newArr[counter++] = arr[i];
      }
   }
   for (int i = 0; i < size; i++) {
      if (arr[i] >= pivot1 && arr[i] <= pivot2) {
         newArr[counter++] = arr[i];
      }
   }
   for (int i = 0; i < size; i++) {
      if (arr[i] > pivot1 && arr[i] > pivot2) {
         newArr[counter++] = arr[i];
      }
   }
   for (int i = 0; i < size; i++) {
      arr[i] = newArr[i];
   }
}

/**
 * @brief      Partition given array into 3 parts based on 2 given pivot indexes
 *             first part contains number less than smaller pivot, 2nd part
 *             contains numbers greater than smaller and greater than larger
 *             pivot and the 3rd and last part contains numbers greater than the
 *             larger pivot. And this algo does this in O(n) time complexity and
 *             Q(1) space complexity using method inspired from hoare's partition
 *
 * @param      arr          The arr
 * @param[in]  size         The size
 * @param[in]  pivotIndex1  The pivot index 1
 * @param[in]  pivotIndex2  The pivot index 2
 */
void dutchFlagSort(int *arr, int size, int pivotIndex1, int pivotIndex2) {
   if(size == 1) {
      return;
   }

   int pivot1 = arr[pivotIndex1], pivot2 = arr[pivotIndex2];
   int low = 1, mid = 1, high = size - 2;

   if (arr[pivotIndex1] > arr[pivotIndex2]) {
      swap(pivot1, pivot2);
   }

   swap(arr[0], arr[pivotIndex1]);
   swap(arr[size - 1], arr[pivotIndex2]);

   while (mid <= high) {
      if (arr[mid] <= pivot1) {
         swap(arr[low], arr[mid]);
         low++;
         mid++;
      } else if (arr[mid] >= pivot2) {
         swap(arr[mid], arr[high]);
         high--;
      } else {
         mid++;
      }
   }

   swap(arr[0], arr[low - 1]);
   swap(arr[size - 1], arr[high + 1]);
}

int main() {
   int arr[]       = { 15, -3, -2, 8, 16, 0, 2, 99, 15, 33, 22, 19, 66, 0 };
   int size        = sizeof(arr) / sizeof(arr[0]);
   int pivotIndex1 = 1;
   int pivotIndex2 = 3;

   dutchFlagSort(arr, size, pivotIndex1, pivotIndex2);
   printArr(arr, size);
   return(0);
}
