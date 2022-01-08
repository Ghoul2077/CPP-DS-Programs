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

vector<int>flattenMatrix(vector<vector<int> > *arr) {
   vector<int> newArr;

   for (auto i = arr->begin(); i < arr->end(); i++) {
      for (auto j = i->begin(); j < i->end(); j++) {
         newArr.push_back(*j);
      }
   }

   return (newArr);
}

/**
 * @brief      Finds the median of a matrix that has all rows sorted in
 *             O(R*Clog(R*C)) time complexity and Q(R*C) space complexity.
 *
 * @param      arr   The array
 *
 * @return     Median of the matrix
 */
float medianOfRowSortedMatrixNaive(vector<vector<int> > *arr) {
   vector<int> flattenedArray = flattenMatrix(arr);

   sort(flattenedArray.begin(), flattenedArray.end());
   int halfSize = flattenedArray.size() / 2;

   if (flattenedArray.size() % 2 == 0) {
      float median = ((float)flattenedArray[halfSize] +
                      (float)flattenedArray[halfSize - 1]) / 2;
      return (median);
   } else {
      float median = flattenedArray[halfSize];
      return (median);
   }
}

/**
 * @brief      Finds the median of a matrix that has all rows sorted & odd
 *             in number of elements in O(R*log(max - min)logC) time complexity
 *             and Q(1) space complexity.
 *
 * @param      arr   The array
 *
 * @return     Median of the matrix
 */

// TODO: Make this algorithm work for even number of elements
float medianOfRowSortedMatrix(vector<vector<int> > *arr) {
   int min = arr->begin()->front(), max = arr->begin()->back();
   bigInt numberOfColumns = (*arr)[0].size();
   bigInt numberOfRows    = arr->size();

   if (numberOfRows * numberOfColumns % 2 == 0) {
      cout << "Even number of elements" << endl;
      return (-1);
   }

   for (bigInt i = 1; i < arr->size(); i++) {
      auto row = arr->begin() + i;

      if (row->at(0) < min) {
         min = row->at(0);
      }

      if (row->at(numberOfColumns - 1) > max) {
         max = row->at(numberOfColumns - 1);
      }
   }

   int medianPosition = (numberOfRows * numberOfColumns + 1) / 2;

   while (min < max) {
      int mid         = (min + max) / 2;
      int midPosition = 0;

      for (bigInt i = 0; i < numberOfRows; i++) {
         auto row = arr->begin() + i;
         midPosition +=
            upper_bound(row->begin(), row->end(), mid) - row->begin();
      }

      if (midPosition < medianPosition) {
         min = mid + 1;
      } else {
         max = mid;
      }
   }

   return ((max + min) / 2);
}

int main() {
   vector<vector<int> > arr = {
      {  1, 2,  3,  4    },
      {  5, 6,  7,  8    },
      {  9, 10, 11, 12   },
      { 13, 14, 15, 16   }
   };

   cout << medianOfRowSortedMatrix(&arr);

   return (0);
}
