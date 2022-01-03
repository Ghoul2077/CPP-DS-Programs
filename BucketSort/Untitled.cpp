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

void insertionSort(vector<int> *arr) {
   for (int i = 1; i < arr->size(); i++) {
      auto curr = arr[i];
      int  j    = i - 1;

      while (arr[j] > curr && j >= 0) {
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = curr;
   }
}

void bucketSort(int *arr, int size, int min, int max) {
   int numberOfBuckets = 5;
   int bucketSize      = ceil(((float)max - (float)min + 1) / numberOfBuckets);
   vector<vector<int> > bucketsArray(numberOfBuckets);
   int counter = 0;

   for (int i = 0; i < size; i++) {
      int bucketSlot = (arr[i] - min) / bucketSize;
      bucketsArray[bucketSlot].push_back(arr[i]);
   }

   for (int i = 0; i < numberOfBuckets; i++) {
      insertionSort(&bucketsArray[i]);
   }

   for (auto i = bucketsArray.begin(); i < bucketsArray.end(); i++) {
      for (auto j = i->begin(); j < i->end(); j++) {
         arr[counter++] = *j;
      }
   }
}

int main() {
   int arr[] = { 20, 50, 40, 10, 30 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int min   = minElement(arr, size);
   int max   = maxElement(arr, size);

   bucketSort(arr, size, min, max);
   printArr(arr, size);

   return (0);
}
