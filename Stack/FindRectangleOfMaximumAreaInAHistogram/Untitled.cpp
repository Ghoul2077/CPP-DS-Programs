#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Gets the maximum area of rectangle if given an array is treated
 *             as bars of histogram. It's time complexity is O(n^2) and space
 *             complexity is Q(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     The maximum area of rectangle.
 */
int getMaximumAreaOfRectangleNaive(int *arr, int size) {
   int maxArea = INT_MIN;

   for (int i = 0; i < size; i++) {
      int currMin = arr[i];

      for (int j = i; j < size; j++) {
         currMin = min(currMin, arr[j]);
         int currArea = currMin * (j - i + 1);
         maxArea = max(maxArea, currArea);
      }
   }

   return (maxArea);
}

/**
 * @brief      Gets the maximum area of rectangle if given an array is treated
 *             as bars of histogram. It's time complexity is O(n) and space
 *             complexity is Q(n). The drawback of this approach is that it
 *             uses 4 individual loops and 2 vectors.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     The maximum area of rectangle.
 */
int getMaximumAreaOfRectangle(int *arr, int size) {
   stack<int>  st1, st2;
   vector<int> arr1, arr2;
   int maxArea = INT_MIN;

   for (int i = 0; i < size; i++) {
      while (!st1.empty() && arr[st1.top()] >= arr[i]) {
         st1.pop();
      }
      int smallerElemIndex = st1.empty() ? -1 : st1.top();
      arr1.push_back(smallerElemIndex);
      st1.push(i);
   }

   for (int i = size - 1; i >= 0; i--) {
      while (!st2.empty() && arr[st2.top()] >= arr[i]) {
         st2.pop();
      }
      int smallerElemIndex = st2.empty() ? size : st2.top();
      arr2.push_back(smallerElemIndex);
      st2.push(i);
   }

   reverse(arr2.begin(), arr2.end());

   for (int i = 0; i < size; i++) {
      int currVal  = arr[i];
      int interval = arr2[i] - arr1[i] - 1;
      int currArea = currVal * interval;
      maxArea = max(maxArea, currArea);
   }

   return (maxArea);
}

/**
 * @brief      Gets the maximum area of rectangle if given an array is treated
 *             as bars of histogram. It's time complexity is O(n) and space
 *             complexity is Q(n). This is the most optimized approach as it
 *             only uses one stack and traverses the array only once.
 *
 * @param      arr   The array
 * @param[in]  size  The size
 *
 * @return     The maximum area of rectangle.
 */
int getMaximumAreaOfRectangleOptimized(int *arr, int size) {
   stack<int> st;
   int maxArea = INT_MIN;

   for (int i = 0; i < size; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
         int top = st.top();
         st.pop();
         int curr = arr[top] * (st.empty() ? i : (i - st.top() - 1));
         maxArea = max(maxArea, curr);
      }
      st.push(i);
   }

   while (!st.empty()) {
      int top = st.top();
      st.pop();
      int curr = arr[top] * (st.empty() ? size : size - st.top() - 1);
      maxArea = max(maxArea, curr);
   }

   return (maxArea);
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
      cout << getMaximumAreaOfRectangleOptimized(arr, size);
      cout << endl;
   }
   return (0);
}
