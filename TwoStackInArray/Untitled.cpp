#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

const int SIZE = 30;

class TwoStacks {
private:
   int *arr, capacity;
   int top1, top2;

public:
   TwoStacks() {
      arr      = new int[SIZE];
      capacity = SIZE;
      top1     = -1;
      top2     = SIZE;
   }

   TwoStacks(int cap) {
      arr      = new int[cap];
      capacity = cap;
      top1     = -1;
      top2     = cap;
   }

   void initialize1() {
      int val;

      cin >> val;

      while (val != -1) {
         this->push1(val);
         cin >> val;
      }
   }

   void initialize2() {
      int val;

      cin >> val;

      while (val != -1) {
         this->push2(val);
         cin >> val;
      }
   }

   void push1(int data) {
      if (top1 == top2 - 1) {
         cout << "Stack 1 Overflow" << endl;
      } else {
         top1++;
         arr[top1] = data;
      }
   }

   void push2(int data) {
      if (top2 == top1 + 1) {
         cout << "Stack 2 Overflow" << endl;
      } else {
         top2--;
         arr[top2] = data;
      }
   }

   void pop1() {
      if (top1 == -1) {
         cout << "Stack 1 Underflow" << endl;
      } else {
         top1--;
      }
   }

   void pop2() {
      if (top2 == capacity) {
         cout << "Stack 2 Underflow" << endl;
      } else {
         top2++;
      }
   }

   void print1() {
      if (this->empty1()) {
         cout << "Stack 1 is empty" << endl;
         return;
      }

      for (int i = top1; i >= 0; i--) {
         cout << arr[i] << " ";
      }
      cout << endl;
   }

   void print2() {
      if (this->empty2()) {
         cout << "Stack 2 is empty" << endl;
         return;
      }

      for (int i = top2; i < capacity; i++) {
         cout << arr[i] << " ";
      }
      cout << endl;
   }

   bool empty1() {
      return (top1 == -1 ? true : false);
   }

   bool empty2() {
      return (top2 == capacity ? true : false);
   }

   int peek1() {
      if (top1 != -1) {
         return (arr[top1]);
      } else {
         return (-1);
      }
   }

   int peek2() {
      if (top2 != capacity) {
         return (arr[top2]);
      } else {
         return (-1);
      }
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      TwoStacks *stack = new TwoStacks(6);
      stack->initialize1();
      stack->initialize2();
      stack->push1(5);
      stack->print2();
      cout << endl;
   }
   return (0);
}
