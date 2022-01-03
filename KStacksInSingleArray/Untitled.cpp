#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

const int SIZE = 30;

class KStacks {
private:
   int *arr, *next, *top;
   int capacity, freeTop;

public:
   KStacks(int numberOfStacks, int cap = SIZE) {
      arr  = new int[cap];
      next = new int[cap];
      top  = new int[numberOfStacks];

      fill(top, top + numberOfStacks, -1);

      for (int i = 1; i < cap; i++) {
         next[i - 1] = i;
      }
      next[cap - 1] = -1;

      capacity = cap;
      freeTop  = 0;
   }

   void initizalize() {
      int val, stackNum;

      cin >> val;

      while (val != -1) {
         cin >> stackNum;
         this->push(val, stackNum);
         cin >> val;
      }
   }

   void push(int val, int stackNum) {
      if (freeTop != capacity) {
         int i = freeTop;
         freeTop       = next[i];
         arr[i]        = val;
         next[i]       = top[stackNum];
         top[stackNum] = i;
      } else {
         cout << "Stack overflow" << endl;
      }
   }

   void pop(int stackNum) {
      if (freeTop == 0) {
         int i = top[stackNum];
         top[stackNum] = next[i];
         next[i]       = freeTop;
         freeTop       = i;
      } else {
         cout << "Stack underflow" << endl;
      }
   }

   void print(int stackNum) {
      int i = top[stackNum];

      if (i == -1) {
         cout << "Stack is empty" << endl;
         return;
      }

      do {
         cout << arr[i] << " ";
         i = next[i];
      } while (i != -1);
   }

   int peek(int stackNum) {
      if (top[stackNum] != -1) {
         return (arr[top[stackNum]]);
      } else {
         cout << "Stack is empty" << endl;
         return (-1);
      }
   }

   bool empty(int stackNum) {
      return (top[stackNum] == -1);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      KStacks *stacks = new KStacks(5, 30);
      stacks->initizalize();
      stacks->print(1);
      cout << endl;
   }
   return (0);
}
