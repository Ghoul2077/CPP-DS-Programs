#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief      Finds a pair with a given sum in sorted array in
 *             O(n) time complexity and Q(1) space complexity. It has advantage
 *             over hashmap method because of space complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 */
void findPairWithSumInSortedArray(int *arr, int size, int sum) {
   int low = 0, high = size - 1;

   while (low <= high) {
      int currSum = arr[low] + arr[high];
      if (currSum == sum) {
         cout << arr[low] << " + " << arr[high];
         break;
      } else if (currSum < sum) {
         low += 1;
      } else {
         high -= 1;
      }
   }
}

/** TODO
 * @brief      Finds a pair with sum in unsorted array using
 *             hashmap.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 */
void findPairWithSumInUnsortedArray(int *arr, int size, int sum) {
}

int main() {
   int arr[] = { 1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000 };
   int size  = sizeof(arr) / sizeof(arr[0]);
   int sum   = 260;

   findPairWithSumInSortedArray(arr, size, sum);
   return(0);
}
