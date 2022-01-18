#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool comparator(pair<int, int>a, pair<int, int>b) {
   return (a.second < b.second);
}

/**
 * @brief      Removes k elements from a given array such that after removal the
 *             number of distinct elements in the array is minimum. The idea
 *             is to use hashmap to store frequencies of the elements and then
 *             duplicate these to a vector of pair(int, int) which we will use
 *             for sorting the elements by frequencies. After sorting loop
 *             through the vector removing elements until value of k becomes 0.
 *             Count the remaining elements and return the number. It's time
 *             complexity is O(nlogn) and it's space complexity is O(n).
 *
 * @param      arr   The array
 * @param[in]  size  The size of array
 * @param[in]  k     Number of items to remove
 *
 * @return     Minimum number of distinct elements possible after removal
 */
int removeKElementsSuchThatLeastNumberOfDistinctElementsRemain(int *arr,
                                                               int  size,
                                                               int  k) {
   unordered_map<int, int> s;
   vector<pair<int, int> > v;

   for (int i = 0; i < size; i++) {
      s[arr[i]]++;
   }

   for (auto& i: s) {
      v.push_back(make_pair(i.first, i.second));
   }
   sort(v.begin(), v.end(), comparator);
   int distinctCount = 0;

   for (auto i : v) {
      int diff = k - i.second;

      if (diff >= 0) {
         k -= i.second;
      } else {
         distinctCount++;
      }
   }
   return (distinctCount);
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int size, k;
      cin >> size;
      int *arr = new int[size];

      for (int i = 0; i < size; i++) {
         cin >> arr[i];
      }
      cin >> k;
      cout << removeKElementsSuchThatLeastNumberOfDistinctElementsRemain(arr,
                                                                         size,
                                                                         k);
      cout << endl;
   }
   return (0);
}
