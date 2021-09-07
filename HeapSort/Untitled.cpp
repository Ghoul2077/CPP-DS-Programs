#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << "  ";
   }
}

void heapify(int *arr, int size, int i) {
   int largest = i, left = 2 * i + 1, right = 2 * i + 2;

   if (left < size && arr[largest] < arr[left]) {
      largest = left;
   }
   if (right < size && arr[largest] < arr[right]) {
      largest = right;
   }
   if (largest != i) {
      swap(arr[largest], arr[i]);
      heapify(arr, size, largest);
   }
}

void buildHeap(int *arr, int size) {
   for (int i = (size - 2) / 2; i >= 0; i--) {
      heapify(arr, size, i);
   }
}

/**
 * @brief      Sorts an array using the heap data structure in O(nlogn) time
 *             complexity in all cases but it is slower than merge sort and
 *             quick sort. (Creating a heap from array is O(n) time complexity).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void heapSort(int *arr, int size) {
   buildHeap(arr, size);
   for(int i = size - 1; i > 0; i--) {
      swap(arr[i], arr[0]);
      heapify(arr, i, 0);
   }
}

int main() {
   int arr[] = { 20, 50, 40, 10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   heapSort(arr, size);
   printArr(arr, size);

   return(0);
}
