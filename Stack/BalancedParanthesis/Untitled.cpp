#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

/**
 * @brief      Finds if given set of paranthesis are balanced or not, by which
 *             we mean that the bracket opened at last should be closed first
 *             and all bracket must be closed to call the brackets balanced.
 *             It's time complexity is O(n) and it's space complexity is Q(n).
 *
 * @param[in]  brackets  The brackets
 */
void areBracketsBalanced(string brackets) {
   if (brackets.size() % 2 != 0) {
      cout << "No";
      return;
   }

   stack<char> bracketStack;

   for (int i = 0; i < brackets.size(); i++) {
      switch (brackets[i]) {
      case '{':
         bracketStack.push('}');
         break;

      case '(':
         bracketStack.push(')');
         break;

      case '[':
         bracketStack.push(']');
         break;

      case '}':
      case ')':
      case ']':

         if (!bracketStack.empty() && (bracketStack.top() == brackets[i])) {
            bracketStack.pop();
         } else {
            cout << "No";
            return;
         }
         break;
      }
   }

   cout << "Yes";
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string brackets;
      getline(cin, brackets);
      areBracketsBalanced(brackets);
      cout << endl;
   }
   return (0);
}
