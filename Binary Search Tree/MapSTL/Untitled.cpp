#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      map<int, int>    m;
      map<string, int> stringMap;

      // First way to insert item in the map
      m.insert({ 10, 200 });
      stringMap.insert({ "A", 200 });
      stringMap.insert({ "B", 300 });

      // Second way to insert item in the map, what it does is it updates the
      // value of the key if it already exists otherwise it inserts that key
      // and assigns the value given in RHS otherwise it just assigns default
      // values to it
      m[5] = 100;
      m[6];

      // Third way to insert item in the map, using "at" member function we get
      // the reference of the the value in LHS which is then updated with value
      // in the RHS. It does not inserts key if it does not exists, if you still
      // try to access that reference it will give outOfRange exception
      m.at(10) = 500;

      // First way to print a map
      for (auto& i: m) {
         cout << i.first << " : " << i.second << endl;
      }

      // Second way to print a map
      for (auto i = stringMap.begin(); i != stringMap.end(); i++) {
         cout << (*i).first << " : " << (*i).second << endl;
      }

      // Method to completely empty a given map
      m.clear();
      cout << "New size of map after invoking clear : " << m.size();

      cout << endl;

      // Find by value of key, return end reference of the map if value not
      // found
      auto it = stringMap.find("A");

      if (it != stringMap.end()) {
         cout << "Found value : " << (*it).second;
      } else {
         cout << "Not found";
      }

      cout << endl;
   }
   return (0);
}
