#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Finds peak elements in a given array in O(n) time complexity,
 *             peak elements are those elements in the array that are greater
 *             than their immediate previous and immediate next element
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Peak element encountered first
 */
int searchPeakElementNaive(int *arr, int size) {
   if ((arr[0] > arr[1]) || (size == 1)) {
      return (arr[0]);
   }

   for (int i = 1; i < size - 1; i++) {
      if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1])) {
         return (arr[i]);
      }
   }

   if (arr[size - 1] > arr[size - 2]) {
      return (arr[size - 1]);
   }

   return (-1);
}

/**
 * @brief      Finds peak elements in a given array in O(logn) time complexity
 *             by exploiting the fact that there is always one peak element
 *             present in any given array rest is done using binary search,
 *             peak elements are those elements in the array that are greater
 *             than their immediate previous and immediate next element
 *
 *             Here's one way to look at how the decision is made at each midpoint.
 *
 *             Imagine you went hiking into the woods and after walking on the trail for a bit, you realized that you wanted to climb a peak. Before you start looking for one, you know that in order to reach a peak, you need to climb up a slope. Here's how the rest of the story plays out (in a 1D world) -
 *
 *             You look to left first (or to the right, if you prefer that).
 *             If the ground is higher to your left, you walk up that slope. As long as you keep walking up the slope, you are climbing uphill and are guaranteed to reach a peak. It doesn't matter if it's Big or small.
 *             If the ground is lower to the left, you are on a slope. You don't want to go there. So, you turn around and look to the right in the hope of finding a peak.
 *             If the ground is higher on the right, you walk up in that direction so that you approach a peak
 *             If the ground is sloping to the right as well, you are already on a peak
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     Peak element encountered first
 */
int searchPeakElement(int *arr, int size) {
   int low = 0, high = size;

   while (low <= high) {
      int mid = (low + high) / 2;

      if (((mid == 0) || (arr[mid - 1] < arr[mid])) &&
          ((mid == size - 1) || (arr[mid + 1] < arr[mid]))) {
         return (arr[mid]);
      }

      if ((mid > 0) && (arr[mid - 1] >= arr[mid])) {
         high = mid - 1;
      } else {
         low = mid + 1;
      }
   }

   return (-1);
}

int main() {
   int arr[] = { 15, 20, 40, 60, 80, 100, 200, 500, 1000, 1, 10 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << searchPeakElement(arr, size);
   return (0);
}
