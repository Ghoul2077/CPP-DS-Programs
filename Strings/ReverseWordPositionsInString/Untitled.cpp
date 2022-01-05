#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;

/**
 * @brief      Reverses given word positions of a string in O(n) time complexity
 *             and Q(n) space complexity. It uses the stack mentality i.e it
 *             uses temporary string instead of stack to reverse the string but
 *             using the principle of stack.
 *
 * @param      str   The string
 *
 * @return     Reversed string
 */
string reverseWordPositionsNaive(string& str) {
   string reversedString = "";
   int    i              = str.size() - 1;

   while (i >= 0) {
      string word = "";

      while (str[i] != ' ' && i >= 0) {
         word = str[i] + word;
         i--;
      }

      i--;

      if (reversedString.size() == 0) {
         reversedString += word;
      } else {
         reversedString += (" " + word);
      }
   }

   return (reversedString);
}

/**
 * @brief      Reverses given word positions of a string in O(n^2) time 
 *             complexity and Q(1) space complexity. In this approach we reverse
 *             each word and then reverse the whole string at the end.
 *             The benefit of this approach is that it reverses the string in
 *             place.
 *             
 * @param      str   The string
 *
 * @return     Reversed string
 */
string reverseWordPositions(string& str) {
   int start = 0;

   for (bigInt end = 0; end < str.size(); end++) {
      if (str[end] == ' ') {
         reverse(str.begin() + start, str.begin() + end);
         while (end < str.size() && str[end] == ' ') {
            end++;
         }
         start = end;
      }
   }

   reverse(str.begin() + start, str.end());
   reverse(str.begin(),         str.end());
   return (str);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      cout << reverseWordPositions(str);
      cout << endl;
   }

   return (0);
}
