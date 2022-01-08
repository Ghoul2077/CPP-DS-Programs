#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds largest area rectangle with all ones when given a boolean
 *             matrix. It's time compleixty is O((RC)^3) and space complexity is
 *             Q(1).
 *
 * @param      arr   The array
 * @param[in]  rows  The rows
 * @param[in]  cols  The cols
 *
 * @return     Rectangle of largest area
 */
int findLargestRectangleWithAllOnesNaive(int **arr, int rows, int cols) {
   int largestAreaOfRectangle = 0;

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         for (int k = i; k < rows; k++) {
            for (int l = j; l < cols; l++) {
               bool areAllOnes = true;

               for (int m = i; m <= k; m++) {
                  for (int n = j; n <= l; n++) {
                     if (arr[m][n] == 0) {
                        areAllOnes = false;
                        break;
                     }
                  }
               }

               if (areAllOnes) {
                  int currAreaOfRectangle = (k - i + 1) * (l - j + 1);
                  largestAreaOfRectangle = max(largestAreaOfRectangle,
                                               currAreaOfRectangle);
               }
            }
         }
      }
   }

   return (largestAreaOfRectangle);
}

int rectangleOfMaxArea(int *arr, int size) {
   stack<int> st;
   int maxArea = 0;

   for (int i = 0; i < size; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
         int top = st.top();
         st.pop();
         int currSize = arr[top] * (st.empty() ? i : (i - st.top() - 1));
         maxArea = max(maxArea, currSize);
      }
      st.push(i);
   }

   while (!st.empty()) {
      int top = st.top();
      st.pop();
      int currSize = arr[top] * (st.empty() ? size : (size - st.top() - 1));
      maxArea = max(maxArea, currSize);
   }

   return (maxArea);
}

/**
 * @brief      Finds largest rectangle with all ones for a given boolean matrix
 *             . This approach is an extension of max area of rectangle in
 *             histogram. It's time complexity is Q(R * C) and space complexity
 *             is Q(C).
 *
 * @param      arr   The array
 * @param[in]  rows  The rows
 * @param[in]  cols  The cols
 *
 * @return     Rectangle with largest area
 */
int findLargestRectangleWithAllOnes(int **arr, int rows, int cols) {
   int res = rectangleOfMaxArea(arr[0], cols);

   for (int i = 1; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         if (arr[i][j] == 1) {
            arr[i][j] += arr[i - 1][j];
         }
      }
      res = max(res, rectangleOfMaxArea(arr[i], cols));
   }

   return (res);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int rows, cols;
      cin >> rows;
      cin >> cols;
      int **arr = new int *[rows];

      for (int i = 0; i < rows; i++) {
         arr[i] = new int[cols];

         for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
         }
      }
      cout << findLargestRectangleWithAllOnes(arr, rows, cols);
      cout << endl;
   }
   return (0);
}
