#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief      Usage of unordered_set which is equivalent of hash map in c++
 */
int main() {
   unordered_map<string, int> map;

   map["some_val"]      = 20;
   map["another_value"] = 40;

   for (auto x: map) {
      cout << x.first << "  " << x.second << endl;
   }

   if (map.find("lol") != map.end()) {
      cout << "Found" << endl;
   } else {
      cout << "Not Found" << endl;
   }

   if (map.count("lol") == 1) {
      cout << "Found" << endl;
   } else {
      cout << "Not Found" << endl;
   }

   return 0;
}
