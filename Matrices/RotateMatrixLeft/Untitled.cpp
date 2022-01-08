#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int> > *arr) {
   for (auto i = arr->begin(); i < arr->end(); i++) {
      for (auto j = i->begin(); j < i->end(); j++) {
         cout << *j << "  ";
      }
      cout << endl;
   }
}

/**
 * @brief      Rotate matrix to left by 90 degree in O(R*C) time complexity and
 *             O(R*C) space complexity.
 *
 * @param      arr   The array
 */
void rotateLeftNaive(vector<vector<int> > *arr) {
   int numberOfColumns = arr->begin()->size();
   vector<vector<int> > newMatrix(numberOfColumns);

   for (int i = numberOfColumns - 1; i >= 0; i--) {
      for (auto j = arr->begin(); j < arr->end(); j++) {
         newMatrix[numberOfColumns - i - 1].push_back((*j)[i]);
      }
   }

   arr->erase(arr->begin());
   *arr = newMatrix;
}

/**
 * @brief      Rotate matrix to left by 90 degree in O(n^2) time complexity and
 *             O(1) space complexity. We first transpose the matrix and then
 *             turn the column upside down.
 *
 * @param      arr   The array
 */
void rotateLeft(vector<vector<int> > *arr) {
   for (long long unsigned int i = 0; i < arr->size(); i++) {
      for (long long unsigned int j = i + 1; j < arr->size(); j++) {
         swap((*arr)[i][j], (*arr)[j][i]);
      }
   }

   for (long long unsigned int i = 0; i < arr->size(); i++) {
      int low = 0, high = arr->size() - 1;

      while (low < high) {
         swap((*arr)[low][i], (*arr)[high][i]);
         low++;
         high--;
      }
   }
}

int main() {
   vector<vector<int> > arr = {
      {  1, 2,  3,  4   },
      {  5, 6,  7,  8   },
      {  9, 10, 11, 12  },
      { 13, 14, 15, 16  }
   };

   rotateLeft(&arr);
   printMatrix(&arr);

   return (0);
}
