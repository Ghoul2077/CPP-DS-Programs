#include <bits/stdc++.h>
using namespace std;

void printBoundaryElements(vector<vector<int> > *arr) {
   auto top  = arr->begin();
   auto down = arr->end() - 1;

   for (auto i = top->begin(); i < top->end(); i++) {
      cout << *i << "  ";
   }

   for (auto i = arr->begin() + 1; i < arr->end(); i++) {
      cout << i->back() << "  ";
   }

   if (arr->size() > 1) {
      for (auto i = down->end() - 2; i >= down->begin(); i--) {
         cout << *i << "  ";
      }
   }

   if ((arr->end() - 1)->size() > 1) {
      for (auto i = arr->end() - 2; i > arr->begin(); i--) {
         cout << i->front() << "  ";
      }
   }
}

int main() {
   vector<vector<int> > arr = { { 1, 2,  3,  4  },
      { 5, 6,  7,  8  },
      { 9, 10, 11, 12 }
   };

   printBoundaryElements(&arr);
   return (0);
}
