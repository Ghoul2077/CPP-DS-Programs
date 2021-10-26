#include <limits.h>
#include <bits/stdc++.h>
#include <new>
using namespace std;

#define SIZE 300

class Stack {
private:
   int stack[SIZE];
   int top = -1;

public:
   void initialize() {
      int data;
      cin >> data;

      while(data != -1) {
         this->push(data);
         cin >> data;
      }
   }

   void push(int data) {
      if(top != SIZE) {
         top++;
         stack[top] = data;
      } else {
         cout << "Stack overflow" << endl;
      }
   }

   void pop() {
      if(top != -1) {
         top--;
      } else {
         cout << "Stack underflow" << endl;
      }
   }

   int peek() {
      if(top != -1) {
         return stack[top];
      } else {
         cout << "Stack is empty" << endl;
         return -1;
      }
   }

   bool isEmpty() {
      return top == -1 ? true : false;
   }

   void print() {
      for(auto i = top; i >= 0; i--) {
         cout << stack[i] << " ";
      }
      cout << endl;
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
      cout << s1->peek() << endl;
      s1->push(5);
      s1->print();
   }

   return (0);
}
