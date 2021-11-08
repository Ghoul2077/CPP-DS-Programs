#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class CustomStack {
private:
   stack<int> st;
   stack<int> auxillaryArr;

public:
   void initialize() {
      int data;
      cin >> data;

      while(data != -1) {
         this->push(data);
         cin >> data;
      }
   }

   int top() {
      return st.top();
   }

   void push(int data) {
      st.push(data);
      if(auxillaryArr.empty() || data <= auxillaryArr.top()) {
         auxillaryArr.push(data);
      } 
   }

   void pop() {
      if(auxillaryArr.top() == st.top()) {
         auxillaryArr.pop();
      }
      st.pop();
   }

   bool isEmpty() {
      return st.empty();
   }

   int getMin() {
      if(auxillaryArr.empty()) {
         return -1;
      }
      return auxillaryArr.top();
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
