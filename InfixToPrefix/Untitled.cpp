#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool isOperator(char ch) {
   switch (ch) {
   case '^':
   case '*':
   case '/':
   case '-':
   case '+':
   case '(':
      return (true);

   default:
      return (false);
   }
}

bool isOperand(char ch) {
   int asciiVal = (int)ch;

   if ((asciiVal >= 65) && (asciiVal <= 90) ||
       (asciiVal >= 97) && (asciiVal <= 122) ||
       (asciiVal >= 48) && (asciiVal <= 57)) {
      return (true);
   }
   return (false);
}

int precedence(char ch) {
   unordered_map<char, int> operatorToPrecedenceMap = {
      { '-', 1 },
      { '+', 1 },
      { '*', 2 },
      { '/', 2 },
      { '^', 3 },
      { '(', 4 },
   };

   return (operatorToPrecedenceMap[ch]);
}

string associativity(char ch) {
   unordered_map<char, string> operatorToPrecedenceMap = {
      { '-', "ltr" },
      { '+', "ltr" },
      { '*', "ltr" },
      { '/', "ltr" },
      { '^', "rtl" },
   };

   return (operatorToPrecedenceMap[ch]);
}

string infixToPrefix(string str) {
   stack<int> st;
   string     prefix = "";

   for (int i = str.size() - 1; i >= 0; i--) {
      if (isOperand(str[i])) {
         prefix += str[i];
      } else if (str[i] == ')') {
         st.push(str[i]);
      } else if (str[i] == '(') {
         while (!st.empty() && st.top() != ')') {
            prefix += st.top();
            st.pop();
         }
         st.pop();
      } else if (isOperator(str[i])) {
         int currPrecedence = precedence(str[i]);

         while (!st.empty() && currPrecedence <= precedence(st.top())) {
            if (precedence(st.top()) == currPrecedence) {
               if (associativity(st.top()) == "ltr") {
                  prefix += st.top();
                  st.pop();
               }
               break;
            } else {
               prefix += st.top();
               st.pop();
            }
         }
         st.push(str[i]);
      }
   }

   while (!st.empty()) {
      prefix += st.top();
      st.pop();
   }

   reverse(prefix.begin(), prefix.end());
   return (prefix);
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string str;
      getline(cin, str);
      cout << infixToPrefix(str);
      cout << endl;
   }
   return (0);
}
