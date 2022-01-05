#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Given array of books with height as values of the array and we
 *             need to find the maximum candies we can store with just two books
 *             used as dam. Time complexity is Q(n) and space complexity is Q(1)
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 *
 * @return     Maximum number of canides possible
 */
int maxCandiesPossibleToStoreWithTwoBooks(int *arr, int size) {
   int maxCandies = 0;
   int left = 0, right = size - 1;

   while (left < right) {
      int width          = right - left - 1;
      int height         = min(arr[left], arr[right]);
      int currMaxCandies = width * height;

      maxCandies = max(maxCandies, currMaxCandies);

      if (arr[left] < arr[right]) {
         left++;
      } else {
         right--;
      }
   }

   return (maxCandies);
}

int main() {
   int arr[] = { 2, 1, 5, 4, 6, 5 };
   int size  = sizeof(arr) / sizeof(arr[0]);

   cout << maxCandiesPossibleToStoreWithTwoBooks(arr, size);
   return (0);
}
