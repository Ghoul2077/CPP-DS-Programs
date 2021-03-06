#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
   list<int>stack;

public:
   void initialize() {
      int data;

      cin >> data;

      while (data != -1) {
         this->push(data);
         cin >> data;
      }
   }

   void push(int data) {
      try {
         stack.push_front(data);
      } catch (bad_alloc& badAlloc) {
         cout << badAlloc.what();
      }
   }

   void pop() {
      if (stack.size() != 0) {
         stack.erase(stack.begin());
      } else {
         cout << "Stack underflow";
      }
   }

   int top() {
      if (stack.size() != 0) {
         return (stack.front());
      } else {
         cout << "Stack is empty";
         return (-1);
      }
   }

   bool isEmpty() {
      return (stack.size() == 0 ? true : false);
   }

   void print() {
      for (auto i = stack.begin(); i != stack.end(); i++) {
         cout << *i << " ";
      }
      cout << endl;
   }

   int size() {
      return (stack.size());
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Stack *s1 = new Stack();
      s1->initialize();
      s1->pop();
      cout << s1->top() << endl;
      s1->push(5);
      s1->print();
   }

   return (0);
}
