#include <iostream>
#include <vector>
#include <experimental/random>
#include <bits/stdc++.h>
using namespace std;

void printArr(vector <pair <int, int> > *arr) {
   for (auto i = arr->begin(); i < arr->end(); i++) {
      cout << i->first << " " << i->second;
      cout << endl;
   }
}

int min(int num1, int num2) {
   return(num1 > num2 ? num2 : num1);
}

int max(int num1, int num2) {
   return(num1 > num2 ? num1 : num2);
}

/**
 * @brief      Merge overlapping intervals by first sorting and then traversing.
 *             It takes O(nlogn) time complexity and O(n) space complexity
 *
 * @param[in]  arr   The arr
 *
 * @return     Vector which contains merged intervals
 */
vector <pair <int, int> > mergeInterval(vector <pair <int, int> > arr) {
   sort(arr.begin(), arr.end(), [](pair <int, int> a, pair <int, int> b) {
      return(a.first < b.first);
   });
   vector <pair <int, int> > mergedArr;
   int res = 0;

   for (int i = 1; i < arr.size(); i++) {
      pair <int, int> *val1 = &arr[res];
      pair <int, int> *val2 = &arr[i];

      if (val1->second >= val2->first) {
         val1->first  = min(val1->first, val2->first);
         val1->second = max(val1->second, val2->second);
      } else {
         mergedArr.push_back(*val1);
         res++;
         *(val1 + 1) = *val2;
      }
   }
   mergedArr.push_back(arr[res]);

   return(mergedArr);
}

int main() {
   vector <pair <int, int> > arr = { { 7, 9 }, { 6, 10 }, { 4, 5 }, { 1, 3 }, { 2, 4 } };

   vector <pair <int, int> > mergedArr = mergeInterval(arr);

   printArr(&mergedArr);

   return(0);
}
