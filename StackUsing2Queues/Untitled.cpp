#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class Stack {
private:
   queue<int>q1;
   queue<int>q2;

public:
   void initialize() {
      int val;

      cin >> val;

      while (val != -1) {
         push(val);
         cin >> val;
      }
   }

   void print() {
      queue<int> copyQueue = q1;

      while (!copyQueue.empty()) {
         cout << copyQueue.front() << " ";
         copyQueue.pop();
      }
      cout << endl;
   }

   void push(int data) {
      while (!q1.empty()) {
         q2.push(q1.front());
         q1.pop();
      }
      q1.push(data);

      while (!q2.empty()) {
         q1.push(q2.front());
         q2.pop();
      }
   }

   void pop() {
      if (q1.size() != 0) {
         q1.pop();
      } else {
         cout << "Queue is empty";
      }
   }

   int top() {
      if (q1.size() != 0) {
         return (q1.front());
      } else {
         cout << "Queue is empty";
         return (-1);
      }
   }

   bigInt size() {
      return (q1.size());
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Stack *s = new Stack();
      s->initialize();
      s->pop();
      s->print();
      cout << endl;
   }
   return (0);
}
