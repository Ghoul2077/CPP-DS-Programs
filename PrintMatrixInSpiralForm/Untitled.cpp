#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      prints a given matrix in spiral form. it uses the technique of
 *             onion peeling by taking 4 variables as corner of the matrix and
 *             gradually lessening them. it's time complexity is q(r * c) because
 *             we reach each cell only once and space complexity is q(1).
 *
 * @param      arr   the matrix
 */
void printspiralmatrix(vector <vector <int> > *arr) {
   int top = 0, left = 0, right = (*arr)[0].size() - 1, bottom = arr->size() - 1;

   while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
         cout << (*arr)[top][i] << "  ";
      }
      top++;
      for (int i = top; i <= bottom; i++) {
         cout << (*arr)[i][right] << "  ";
      }
      right--;
      if (top <= bottom) {
         for (int i = right; i >= left; i--) {
            cout << (*arr)[bottom][i] << "  ";
         }
         bottom--;
      }
      if (left <= right) {
         for (int i = bottom; i >= top; i--) {
            cout << (*arr)[i][left] << "  ";
         }
         left++;
      }
   }
}

int main() {
   vector <vector <int> > arr = {
      {  1,  2,  3,  4 },
      {  5,  6,  7,  8 },
      {  9, 10, 11, 12 },
      { 13, 14, 15, 16 }
   };

   printspiralmatrix(&arr);

   return(0);
}
