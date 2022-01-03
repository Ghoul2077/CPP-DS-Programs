#include <bits/stdc++.h>
using namespace std;

int max(int num1, int num2) {
   return (num1 > num2 ? num1 : num2);
}

int min(int num1, int num2) {
   return (num1 < num2 ? num1 : num2);
}

int majorityElementNaive(int *arr, int size) {
   int majorityElement = -1;

   for (int i = 0; i < size; i++) {
      int count = 1;

      for (int j = 0; j < size; j++) {
         if (arr[j] == arr[i]) {
            count++;
         }
      }

      if (count > size / 2) {
         majorityElement = arr[i];
         break;
      }
   }
   return (majorityElement);
}

int findMajorityCandidate(int *arr, int size) {
   int res = arr[0], count = 1;

   for (int i = 0; i < size; i++) {
      if (arr[i] == res) {
         count++;
      } else {
         count--;
      }

      if (count == 0) {
         res   = arr[i];
         count = 1;
      }
   }

   return (res);
}

/**
 * @brief      Finds the majority element in O(n) time complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Majority element if there is any otherwise 1
 */
int majorityElement(int *arr, int size) {
   int majorityElement = findMajorityCandidate(arr, size);
   int count           = 0;

   for (int i = 0; i < size; i++) {
      if (arr[i] == majorityElement) {
         count++;
      }
   }

   if (count > size / 2) {
      return (majorityElement);
   } else {
      return (-1);
   }
}

int main() {
   int arr[]      = { 8, 8, 6, 6, 6, 4, 6 };
   const int size = sizeof(arr) / sizeof(arr[0]);

   cout << majorityElement(arr, size);
   return (0);
}
