#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector <vector <int> > *arr) {
   for (auto i = arr->begin(); i < arr->end(); i++) {
      for (auto j = i->begin(); j < i->end(); j++) {
         cout << *j << "  ";
      }
      cout << endl;
   }
}

vector <vector <int> > transposeNaive(vector <vector <int> > *arr) {
   int numberOfColumns = arr->begin()->size();
   vector <vector <int> > transposedMatrix(numberOfColumns);

   for (int i = 0; i < numberOfColumns; i++) {
      for (auto j = arr->begin(); j < arr->end(); j++) {
         transposedMatrix[i].push_back((*j)[i]);
      }
   }

   return(transposedMatrix);
}

void transpose(vector <vector <int> > *arr) {
   if (arr->size() != arr->begin()->size()) {
      cout << "Not a sqaure matrix";
      return;
   }

   for (long long unsigned int i = 0; i < arr->size(); i++) {
      for (long long unsigned int j = i; j < arr->size(); j++) {
         swap((*arr)[i][j], (*arr)[j][i]);
      }
   }
}

int main() {
   vector <vector <int> > arr = { {  1,  2,  3,  4 },
      {  5,  6,  7,  8 },
      {  9, 10, 11, 12 },
      { 13, 14, 15, 16 }
   };

   transpose(&arr);
   printMatrix(&arr);

   return(0);
}
