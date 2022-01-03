#include <bits/stdc++.h>
using namespace std;

/**
 * @brief      Usage of unordered_set which is equivalent of hash map in c++
 */
int main() {
   unordered_set<int> set;

   set.insert(40);
   set.insert(50);
   set.insert(100);
   set.insert(90);

   for (int x: set) {
      cout << x << "  ";
   }

   return (0);
}
