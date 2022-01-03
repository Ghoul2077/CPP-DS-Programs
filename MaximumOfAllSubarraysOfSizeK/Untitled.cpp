#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

int getMax(int *arr, int size) {
   int currMax = arr[0];

   for (int i = 1; i < size; i++) {
      currMax = max(currMax, arr[i]);
   }
   return (currMax);
}

/**
 * @brief      Finds the maximum of each K sized subarray of given array arr.
 *             It's time complexity is O(n*k) and space complexity is Q(1).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     size of subarrays
 */
void maximumOfAllSubarraysOfSizeKNaive(int *arr, int size, int k) {
   for (int i = 0; i <= size - k; i++) {
      cout << getMax(arr + i, k) << " ";
   }
}

/**
 * @brief      Finds the maximum of each K sized subarray of given array arr.
 *             It's time complexity is O(2*n) and space complexity is O(n). This
 *             approach uses deque which allows insertion and deletion on front
 *             and back in O(1) time complexity.
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 * @param[in]  k     size of subarrays
 */
void maximumOfAllSubarraysOfSizeK(int *arr, int size, int k) {
   deque<int> dq;

   for (int i = 0; i < k; i++) {
      while (!dq.empty() && arr[i] >= arr[dq.back()]) {
         dq.pop_back();
      }
      dq.push_back(i);
   }

   for (int i = k; i < size; i++) {
      cout << arr[dq.front()] << " ";

      while (!dq.empty() && dq.front() <= i - k) {
         dq.pop_front();
      }

      while (!dq.empty() && arr[i] >= arr[dq.back()]) {
         dq.pop_back();
      }
      dq.push_back(i);
   }
   cout << arr[dq.front()];
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, k;
      cin >> size;
      cin >> k;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      maximumOfAllSubarraysOfSizeKNaive(arr, size, k);
      cout << endl;
   }
   return (0);
}
