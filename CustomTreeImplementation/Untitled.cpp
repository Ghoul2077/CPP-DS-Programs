#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class Deque {
private:
   list<int>deque;
   int capacity;

public:
   Deque(int size = 300) {
      capacity = size;
   }

   void print() {
      if (deque.size() != 0) {
         for (auto i : deque) {
            cout << i << " ";
         }
         cout << endl;
      } else {
         cout << "Deque is empty" << endl;
      }
   }

   void pushFront(int data) {
      if (deque.size() != capacity) {
         deque.push_front(data);
      } else {
         cout << "Deque overflow" << endl;
      }
   }

   void pushBack(int data) {
      if (deque.size() != 0) {
         deque.push_back(data);
      } else {
         cout << "Deque underflow" << endl;
      }
   }

   void popFront() {
      if (deque.size() != 0) {
         deque.pop_front();
      } else {
         cout << "Deque is empty" << endl;
      }
   }

   void popBack() {
      if (deque.size() != 0) {
         deque.pop_back();
      } else {
         cout << "Deque is empty" << endl;
      }
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Deque *q = new Deque();
      q->pushFront(30);
      q->print();
      q->pushFront(40);
      q->popBack();
      q->print();
      cout << endl;
   }
   return (0);
}
