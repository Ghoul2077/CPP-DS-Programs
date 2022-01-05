#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

void printmatrix(vector<vector<int> > *arr) {
   for (auto i = arr->begin(); i < arr->end(); i++) {
      for (auto j = i->begin(); j < i->end(); j++) {
         cout << *j << "  ";
      }
      cout << endl;
   }
}

/**
 * @brief      Searches a sorted matrix (Both rows & cols sorted) for a given
 *             value in O(R * C)  time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  val   The value
 */
void searchInSortedMatrixNaive(vector<vector<int> > *arr, int val) {
   for (bigInt i = 0; i < arr->size(); i++) {
      for (bigInt j = 0; j < (*arr)[0].size(); j++) {
         if ((*arr)[i][j] == val) {
            cout << "(" << i << "," << j << ")";
            return;
         }
      }
   }
   cout << "Not Found";
   return;
}

/**
 * @brief      Searches a sorted matrix (Both rows & cols sorted) for a given
 *             value in O(R + C)  time complexity and Q(1) space complexity.
 *
 * @param      arr   The arr
 * @param[in]  val   The value
 */
void searchInSortedMatrix(vector<vector<int> > *arr, int val) {
   bigInt rowPtr = arr->size() - 1, colPtr = 0;
   bigInt numberOfRows = (*arr)[0].size();

   while (rowPtr >= 0 && colPtr < numberOfRows) {
      int currVal = (*arr)[rowPtr][colPtr];

      if (currVal == val) {
         cout << "(" << rowPtr << "," << colPtr << ")";
         return;
      } else if (currVal < val) {
         colPtr++;
      } else {
         rowPtr--;
      }
   }

   cout << "Not Found";
}

int main() {
   vector<vector<int> > arr = {
      {  1, 2,  3,  4  },
      {  5, 6,  7,  8  },
      {  9, 10, 11, 12 },
      { 13, 14, 15, 16 }
   };

   searchInSortedMatrix(&arr, 17);

   return (0);
}
