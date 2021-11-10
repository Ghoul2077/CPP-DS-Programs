#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

bool isoperator(char ch) {
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

bool isoperand(char ch) {
   int asciival = (int)ch;

   if ((asciival >= 48) && (asciival <= 57)) {
      return (true);
   }
   return (false);
}

float evaluate(float a, float b, char operand) {
   switch (operand) {
   case '+':
      return ((float)a + (float)b);

   case '-':
      return ((float)a - (float)b);

   case '*':
      return ((float)a * (float)b);

   case '/':
      return ((float)a / (float)b);

   case '^':
      return (pow(a, b));

   default:
      return (-1);
   }
}

float evaluatePostfix(string str) {
   stack<float> st;

   for (int i = 0; i < str.size(); i++) {
      if (isoperand(str[i])) {
         float valToPush = (float)str[i] - 48;
         st.push(valToPush);
      } else if (isoperator(str[i])) {
         float val1 = st.top();
         st.pop();
         float val2 = st.top();
         st.pop();
         float currVal = evaluate(val2, val1, str[i]);
         st.push(currVal);
      }
   }

   return (st.top());
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      string infixExpression;
      getline(cin, infixExpression);
      cout << evaluatePostfix(infixExpression);
      cout << endl;
   }
   return (0);
}
