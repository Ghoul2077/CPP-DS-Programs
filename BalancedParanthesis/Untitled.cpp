#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

void areBracketsBalanced(string brackets) {
   if(brackets.size() % 2 != 0) {
      cout << "No";
      return;
   }

   stack<char> bracketStack;

   for(int i = 0; i < brackets.size(); i++) {
      switch(brackets[i]) {
         case '{' : 
         bracketStack.push('}');
         break;
         case '(' : 
         bracketStack.push(')');
         break;
         case '[' : 
         bracketStack.push(']');
         break;
         case '}' : 
         case ')' : 
         case ']' : 
         if(!bracketStack.empty() && bracketStack.top() == brackets[i]) {
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
