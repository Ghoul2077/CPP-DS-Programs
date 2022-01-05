#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

void printVector(vector<bigInt>& arr) {
   for (auto i : arr) {
      cout << i << "  ";
   }
}

bigInt lpsCount(string& str) {
   vector<int> answer;
   unordered_set<string> prefixSet, suffixSet;
   string prefix = "", suffix = "";

   prefixSet.insert(prefix);
   suffixSet.insert(suffix);

   for (bigInt i = 0; i < str.size(); i++) {
      if (prefix.size() < str.size() - 1) {
         prefix = prefix + str[i];
      }

      suffix = str[str.size() - i - 1] + suffix;

      prefixSet.insert(prefix);
      suffixSet.insert(suffix);
   }

   bigInt maxLen = 0;

   for (auto i : prefixSet) {
      if (suffixSet.count(i) == 1) {
         bigInt currSize = i.size();
         maxLen = max(currSize, maxLen);
      }
   }

   return (maxLen);
}

/**
 * @brief      Makes a longest prefix suffix (proper prefix which is also suffix)
 *             length array in O(n^2) time complexity and O(n^2) space complexity
 *             by making use of unordered sets.
 *
 * @param      str   The string
 *
 * @return     Vector array containing the length of longest prefix suffix for
 *             substring from 0 to i (index).
 */
vector<bigInt>lspArray(string& str) {
   vector<bigInt> answer;

   for (bigInt i = 0; i < str.size(); i++) {
      string currString = str.substr(0, i + 1);
      answer.push_back(lpsCount(currString));
   }

   return (answer);
}

/**
 * @brief      Makes a longest prefix suffix (proper prefix which is also suffix)
 *             length array in O(n) time complexity and Q(1) space complexity
 *             using reccursion.
 *
 * @param      str   The string
 *
 * @return     Vector array containing the length of longest prefix suffix for
 *             substring from 0 to i (index).
 */
vector<bigInt>lspArrayOptimized(string& str) {
   bigInt len = 0, i = 1;
   vector<bigInt> answer;

   answer.push_back(0);

   while (i < str.size()) {
      if (str[i] == str[len]) {
         answer.push_back(++len);
         i++;
      } else {
         if (len == 0) {
            answer.push_back(0);
            i++;
         } else {
            len = answer[len - 1];
         }
      }
   }

   return (answer);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      vector<bigInt> arr = lspArrayOptimized(str);
      printVector(arr);
      cout << endl;
   }

   return (0);
}
