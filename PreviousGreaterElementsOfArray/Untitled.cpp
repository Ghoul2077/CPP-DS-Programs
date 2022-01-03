#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds a previous greater element of every element in the given
 *             array. It is the naive approach of this problem with where time
 *             complexity is O(n^2) and space complexity is O(1).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void findPreviousGreaterElementsNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int j;

      for (j = i - 1; j >= 0; j--) {
         if (arr[j] > arr[i]) {
            cout << arr[j] << " ";
            break;
         }
      }

      if (j == -1) {
         cout << -1 << " ";
      }
   }
}

/**
 * @brief      Finds a previous greater element of every element in the given
 *             array. It's a variation of stock span problem and it's time
 *             complexity is O(n) because every element is inserted and removed
 *             only once and space complexity is O(n).
 *
 * @param      arr   The arr
 * @param[in]  size  The size
 */
void findPreviousGreaterElements(int *arr, int size) {
   stack<int> st;

   st.push(arr[0]);
   cout << -1 << " ";

   for (int i = 1; i < size; i++) {
      while (!st.empty() && st.top() <= arr[i]) {
         st.pop();
      }
      int biggerValue = st.empty() ? -1 : st.top();
      cout << biggerValue << " ";
      st.push(arr[i]);
   }
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
      findPreviousGreaterElementsNaive(arr, size);
      cout << endl;
   }
   return (0);
}
