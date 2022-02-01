#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


/**
 * @brief      Finds a maximum water that can be stored by choosing any 2 of the
 *             given lines from the array of line heights. In this bruteforce
 *             approach we check every pair of lines and find the max value out
 *             of all pairs using kadane's max value algorithm. It's time
 *             complexity is O(n^2) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 *
 * @return     Maximum water that can be stored
 */
int findMaximumWaterThatCanBeStoredNaive(int *arr, int size) {
   int maximumWater = INT_MIN;

   for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
         maximumWater = max(min(arr[i], arr[j]) * (j - i), maximumWater);
      }
   }
   return (maximumWater);
}

/**
 * @brief      Finds a maximum water that can be stored by choosing any 2 of the
 *             given lines from the array of line heights. The idea is to use 2
 *             pointer approach. Initially we keep left pointer to first index
 *             and right pointer to last index then we keep moving pointer with
 *             smaller value nearer to other. Across this process we keep track
 *             of maximum water and at last return it. The reason why this
 *             solution works is because we initially start with maximum width
 *             so width problem get taken care along the way as we always end
 *             up with max width possible for the solution and as for the height
 *             our aim is to maximise both the lines so if we move our bigger
 *             line we our potentially leading to a smaller or equal solution
 *             hence we only move the smaller one only out of the 2 because it
 *             has both chances of giving smaller solution or bigger. It's time
 *             complexity is O(n) and it's space complexity is O(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size of the array
 *
 * @return     Maximum water that can be stored
 */
int findMaximumWaterThatCanBeStored(int *arr, int size) {
   int left = 0, right = size - 1;
   int maximumWater = INT_MIN;

   while (left < right) {
      maximumWater = max(min(arr[left], arr[right]) * (right - left),
                         maximumWater);

      if (arr[left] < arr[right]) {
         left++;
      } else {
         right--;
      }
   }
   return (maximumWater);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cout << findMaximumWaterThatCanBeStored(arr, size);
      cout << endl;
   }
   return (0);
}
