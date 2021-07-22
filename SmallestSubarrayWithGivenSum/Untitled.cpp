#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief      Find smallest subarray with the given sum using sliding window
 *             algorithm (Only works if all elements of array are positive) in
 *             O(n + n) == O(n) time compleity and Q(1) space complexity
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  sum   The sum
 *
 * @return     Length of smallest subarray
 */
int smallestSubarrayWithGivenSum(int *arr, int size, int sum) {
   int windowStart = 0, windowEnd;
   int minWindowSize = INT_MAX;
   int windowSum     = 0;

   for (windowEnd = 0; windowEnd < size; windowEnd++) {
      windowSum += arr[windowEnd];
      while (sum < windowSum && windowStart <= windowEnd) {
         windowSum -= arr[windowStart++];
      }
      int windowSize = windowEnd - windowStart + 1;
      if(windowSum == sum && windowSize < minWindowSize) minWindowSize = windowSize;
   }
   return minWindowSize == numeric_limits<int>::max() ? 0 : minWindowSize;
}

int main() {
   int       arr[] = { 1, 8, 30, 5, 20, 7, 3 };
   int       sum   = 30;
   const int size  = sizeof(arr) / sizeof(arr[0]);

   cout << smallestSubarrayWithGivenSum(arr, size, sum);
   return(0);
}
