#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class CustomStack {
private:
   stack<int>st;
   int min;

public:
   CustomStack() {
      min = -1;
   }

   void initialize() {
      int data;

      cin >> data;

      while (data != -1) {
         this->push(data);
         cin >> data;
      }
   }

   int top() {
      if (!st.empty()) {
         int num = st.top();
         return (num <= min ? min : num);
      } else {
         cout << "Stack is empty";
      }
   }

   void push(int data) {
      if (st.empty()) {
         min = data;
         st.push(data);
      } else if (data <= min) {
         st.push(2 * data - min);
         min = data;
      } else {
         st.push(data);
      }
   }

   void pop() {
      if (!st.empty()) {
         int num = st.top();
         st.pop();

         if (num <= min) {
            min = 2 * min - num;
         }
      } else {
         cout << "Stack is empty" << endl;
      }
   }

   bool isEmpty() {
      return (st.empty());
   }

   int getMin() {
      if (min == -1) {
         cout << "No minimum found" << endl;
      }
      return (min);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      CustomStack st;
      st.initialize();
      st.pop();
      cout << st.getMin();
      cout << endl;
   }
   return (0);
}
