#include <limits.h>
#include <bits/stdc++.h>
#include <new>
using namespace std;

class Stack {
private:
   list<int> head;

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
      try {
         head.push_front(data);
      } catch(bad_alloc& badAlloc) {
         cout << badAlloc.what();
      }
   }

   void pop() {
      if(head.size() != 0) {
         head.erase(head.begin());
      } else {
         cout << "Stack underflow";
      }
   }

   int top() {
      if(head.size() != 0) {
         return head.front();
      } else {
         cout << "Stack is empty";
         return -1;
      }
   }

   bool isEmpty() {
      return head.size() == 0 ? true : false;
   }

   void print() {
      for(auto i = head.begin(); i != head.end(); i++) {
         cout << *i << " ";
      }
      cout << endl;
   }

   int size() {
      return head.size();
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
