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

float evaluatePrefix(string prefixExpression) {
   stack<float> st;

   for (int i = prefixExpression.size() - 1; i >= 0; i--) {
      if (isOperand(prefixExpression[i])) {
         float val = (float)prefixExpression[i] - 48;
         st.push(val);
      } else if (isOperator(prefixExpression[i])) {
         float val1 = st.top();
         st.pop();
         float val2 = st.top();
         st.pop();
         float currVal = evaluate(val1, val2, prefixExpression[i]);
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
      string prefixExpression;
      getline(cin, prefixExpression);
      cout << evaluatePrefix(prefixExpression);
      cout << endl;
   }
   return (0);
}
