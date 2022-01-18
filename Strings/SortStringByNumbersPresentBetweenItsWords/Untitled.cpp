#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      This function sorts the given words in a string according to the
 *             number that appears in between the words of that string eg.
 *             aga2in < s11ome. The idea behind this method is to use a ordered
 *             map or tree and store each word as number : string pair in a
 *             single level traversal only and then we just iterate over the map
 *             and store the new values in the array. It's time complexity is
 *             O(nlogn) and it's space complexity is O(n).
 *
 * @param      str   The string
 */
void sortByNumberPresentBetweenCharactersInTheString(string& str) {
   map<int, string> rankingMap;
   string prevString = "";
   int    stringNum  = 0;

   for (int i = 0; i < str.size(); i++) {
      int asciiVal = str[i];

      if (str[i] == ' ') {
         rankingMap.insert({ stringNum, prevString });
         prevString = "";
         stringNum  = 0;
         continue;
      }

      if ((asciiVal >= 48) && (asciiVal <= 57)) {
         stringNum = stringNum * 10 + (asciiVal - 48);
      }
      prevString += str[i];
   }
   rankingMap.insert({ stringNum, prevString });

   int prevSize = str.size();

   str = "";

   for (auto& i : rankingMap) {
      if (str != "") {
         str += " ";
      }
      str += i.second;
   }
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      sortByNumberPresentBetweenCharactersInTheString(str);
      cout << str;
      cout << endl;
   }
   return (0);
}
