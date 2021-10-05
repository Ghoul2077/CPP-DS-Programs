#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Finds if a string 2 is rotations of string 1 in O(n^2) time
 *             and Q(1) space complexity compleixty by traversing and comparing 
 *             full string starting from each index. 
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if is rotation, False otherwise
 */
bool checkForRotationNaive(string& str1, string& str2) {
   if (str1.size() != str2.size()) {
      return (false);
   }

   bigInt i = 0, j = 0;

   while (j < str1.size()) {
      for (i = 0; i < str1.size(); i++) {
         int indexVal = (j + i) % str2.size();

         if (str1[i] != str2[indexVal]) {
            j++;
            break;
         }
      }

      if (i == str1.size()) {
         return (true);
      } else {
         continue;
      }
   }

   return (false);
}

/**
 * @brief      Finds if a string 2 is rotations of string 1 in O(n) time
 *             and Q(n) space complexity compleixty by traversing and comparing 
 *             full string starting from each index. 
 *
 * @param      str1  The string 1
 * @param      str2  The string 2
 *
 * @return     True if is rotation, False otherwise
 */
bool checkForRotation(string &str1, string &str2) {
   if(str1.size() != str2.size()) {
      return false;
   }
   bool isPresent = ((str1 + str1).find(str2) != string::npos);
   return isPresent;
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str1, str2;
      getline(cin, str1);
      getline(cin, str2);
      cout << checkForRotation(str1, str2);
      cout << endl;
   }

   return (0);
}
