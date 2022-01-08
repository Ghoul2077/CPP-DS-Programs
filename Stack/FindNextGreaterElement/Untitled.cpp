#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds next greater elements to the right of every element. It's
 *             time complexity is O(n^2) and space complexity is Q(1).
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void findNextGreaterElementsNaive(int *arr, int size) {
   for (int i = 0; i < size; i++) {
      int j;

      for (j = i + 1; j < size; j++) {
         if (arr[j] > arr[i]) {
            cout << arr[j] << " ";
            break;
         }
      }

      if (j == size) {
         cout << -1 << " ";
      }
   }
}

/**
 * @brief      Finds next greater elements to the right of every element. It is
 *             a variant of stock span problem. It's time complexity is O(n) and
 *             space complexity is Q(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size
 */
void findNextGreaterElements(int *arr, int size) {
   vector<int> reverseArr(size);
   stack<int>  st;

   for (int i = size - 1; i >= 0; i--) {
      while (!st.empty() && st.top() < arr[i]) {
         st.pop();
      }
      int biggerElem = st.empty() ? -1 : st.top();
      reverseArr.push_back(biggerElem);
      st.push(arr[i]);
   }

   reverse(reverseArr.begin(), reverseArr.end());

   for (int i = 0; i < size; i++) {
      cout << reverseArr[i] << " ";
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
      findNextGreaterElementsNaive(arr, size);
      cout << endl;
   }
   return (0);
}
