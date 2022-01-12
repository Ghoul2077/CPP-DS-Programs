#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

void printArr(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
}

/**
 * @brief      Gets the ceiling to the left of each element in the given array.
 *             Ceil is equal or greater value. It's time complexity is O(n^2) &
 *             it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     Array containing ceil values for every index.
 */
int* getCeilToTheLeftNaive(int *arr, int size) {
   int *ceil = new int[size];

   for (int i = 0; i < size; i++) {
      int smallestMax = INT_MAX;

      for (int j = 0; j < i; j++) {
         if (arr[j] >= arr[i]) {
            smallestMax = min(smallestMax, arr[j]);
         }
      }

      if (smallestMax == INT_MAX) {
         smallestMax = -1;
      }
      ceil[i] = smallestMax;
   }

   return (ceil);
}

/**
 * @brief      Gets the ceiling to the left of each element in the given array.
 *             Ceil is equal or greater value. The idea we use in the below
 *             approach is the ability of tree to sort incoming stream of values
 *             , while traversing values of array we keep adding them to a set
 *             STL (which is nothing but Red Black Tree underneath). Now we find
 *             the lower bound of our current value of iteration of array in the
 *             set which becomes our ceil for that value to the left. It's time
 *             complexity is O(nlogn) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 *
 * @return     Array containing ceil values for every index.
 */
int* getCeilToTheLeft(int *arr, int size) {
   set<int> s;
   int     *ceil = new int[size];

   for (int i = 0; i < size; i++) {
      auto lowerBoundToLeft = s.lower_bound(arr[i]);

      if (lowerBoundToLeft != s.end()) {
         ceil[i] = *lowerBoundToLeft;
      } else {
         ceil[i] = -1;
      }
      s.insert(arr[i]);
   }

   return (ceil);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      printArr(getCeilToTheLeft(arr, size), size);
      cout << endl;
   }
   return (0);
}
