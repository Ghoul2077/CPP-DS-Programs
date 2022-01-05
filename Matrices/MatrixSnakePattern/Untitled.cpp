#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Prints a matrix in snake pattern i.e first row from left to right
 *             next row from right to left and so on. It's time complexity is
 *             Q(R * C) where r is number of rows and c is number of columns.
 *
 * @param      arr   The arr
 */
void printMatrixInSnakePattern(vector<vector<int> > *arr) {
   int counter = 0;

   for (auto i = arr->begin(); i < arr->end(); i++) {
      if (counter % 2 == 0) {
         for (auto j = i->begin(); j < i->end(); j++) {
            cout << *j << "  ";
         }
      } else {
         for (auto j = i->end() - 1; j >= i->begin(); j--) {
            cout << *j << "  ";
         }
         counter++;
      }
      cout << endl;
   }
}

int main() {
   vector<vector<int> > arr = { { 1, 2,  3,  4  },
      { 5, 6,  7,  8  },
      { 9, 10, 11, 12 }
   };

   printMatrixInSnakePattern(&arr);
   return (0);
}
