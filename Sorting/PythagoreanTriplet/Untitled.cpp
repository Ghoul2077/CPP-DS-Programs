#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds a pythagorean triplet in sorted array in O(n^2) time
 *             complexity & Q(1) space complexity using two pointer approach.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void findPythagoreanTripletInSortedArray(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int low = i + 1, high = size - 1;
      int diff = arr[i] * arr[i];

      while (low <= high) {
         int sqrDiff = (arr[high] * arr[high]) - (arr[low] * arr[low]);

         if (sqrDiff == diff) {
            cout << arr[i] << "^2 + " << arr[low] << "^2 = " << arr[high] <<
               "^2";
            return;
         } else if (sqrDiff < diff) {
            low += 1;
         } else {
            high -= 1;
         }
      }
   }
   cout << "Not Found";
}

int main() {
   int arr[] = { 1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   findPythagoreanTripletInSortedArray(arr, size);
   return (0);
}
