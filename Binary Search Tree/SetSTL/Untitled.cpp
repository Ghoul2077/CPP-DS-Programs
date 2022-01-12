#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      set<int> setIncreasingOrder;
      set<int, greater<int> > setDecreasingOrder;

      setIncreasingOrder.insert(10);
      setIncreasingOrder.insert(40);
      setIncreasingOrder.insert(5);

      setDecreasingOrder.insert(10);
      setDecreasingOrder.insert(40);
      setDecreasingOrder.insert(5);


      // Printing a set using begin and end iterators
      for (auto it = setIncreasingOrder.begin();
           it != setIncreasingOrder.end();
           it++
           ) {
         cout << *it << " ";
      }

      cout << endl;

      // Printing set using just auto iterators
      for (auto i : setDecreasingOrder) {
         cout << i << " ";
      }

      cout << endl;

      // Search function in set using find
      auto findResult = setIncreasingOrder.find(5);

      if (findResult == setIncreasingOrder.end()) {
         cout << "5 not found";
      } else {
         cout << "5 found";
      }

      cout << endl;

      // Search function in set using count
      if (setIncreasingOrder.count(11) == 0) {
         cout << "11 not found";
      } else {
         cout << "11 found";
      }

      cout << endl;

      // Delete value from set using value
      setIncreasingOrder.erase(40);

      // Delete value from set using iterator
      auto it = setIncreasingOrder.find(10);
      setIncreasingOrder.erase(it);

      // Delete a range of values using iterator. Erase method takes a starting
      // iterator and one ending iterator deleting everything in between
      // inclusive of both of them
      auto _it = setDecreasingOrder.find(5);
      setDecreasingOrder.erase(_it, setDecreasingOrder.end());

      // Find lower bound of a given value from the set (lower bound is the
      // first larger or equal element in the given data structure)
      auto it_ = setIncreasingOrder.lower_bound(4);

      if (it_ != setIncreasingOrder.end()) {
         cout << *it_;
      } else {
         cout << "Value is already greater than largest value of set";
      }

      cout << endl;

      // Clear the set (Make it empty again)
      setIncreasingOrder.clear();
   }
   return (0);
}
