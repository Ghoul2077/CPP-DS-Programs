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

void infixToPostfix(string str) {
   stack<char> st;

   for (int i = 0; i < str.size(); i++) {
      if (isOperand(str[i])) {
         cout << str[i];
      } else if (str[i] == ')') {
         while (st.top() != '(') {
            cout << st.top();
            st.pop();
         }
         st.pop();
      } else if (isOperator(str[i])) {
         int currOperatorPrecendence = precedence(str[i]);

         while (!st.empty() && st.top() != '(' &&
                currOperatorPrecendence <= precedence(st.top())) {
            if ((currOperatorPrecendence == precedence(st.top()))) {
               if (associativity(st.top()) == "ltr") {
                  cout << st.top();
                  st.pop();
               }
               break;
            } else {
               cout << st.top();
               st.pop();
            }
         }
         st.push(str[i]);
      }
   }

   while (!st.empty()) {
      cout << st.top();
      st.pop();
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string infixExpression;
      getline(cin, infixExpression);
      infixToPostfix(infixExpression);
      cout << endl;
   }
   return (0);
}
