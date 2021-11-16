#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class Deque {
private:
   int *arr;
   int top;
   int capacity;
   int size;

public:
   Deque() {
      arr      = new int[300];
      top      = 0;
      size     = 0;
      capacity = 300;
   }

   void print() {
      if (size != 0) {
         int i    = top;
         int rear = (top + size - 1) % capacity;

         while (i != (rear + 1) % capacity) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
         }
         cout << endl;
      } else {
         cout << "Deque is empty" << endl;
      }
   }

   void pushFront(int data) {
      if (size != capacity) {
         if (size != 0) {
            top = (top - 1 + capacity) % capacity;
         }
         arr[top] = data;
         size++;
      } else {
         cout << "Deque is full" << endl;
      }
   }

   void pushBack(int data) {
      if (size != capacity) {
         int rear    = (top + size - 1) % capacity;
         int newRear = (rear + 1) % capacity;
         arr[newRear] = data;
         size++;
      } else {
         cout << "Deque is full" << endl;
      }
   }

   void popFront() {
      if (size != 0) {
         top = (top + 1) % capacity;
         size--;
      } else {
         cout << "Deque is already empty" << endl;
      }
   }

   void popBack() {
      if (size != 0) {
         size--;
      } else {
         cout << "Deque is already empty" << endl;
      }
   }

   int getFront() {
      if (size != 0) {
         return (arr[top]);
      } else {
         cout << "Deque is empty" << endl;
         return (-1);
      }
   }

   int getRear() {
      if (size != 0) {
         int rear = (top + size - 1) % capacity;
         return (arr[rear]);
      } else {
         cout << "Deque is empty" << endl;
         return (-1);
      }
   }

   bool isFull() {
      return (size == capacity);
   }

   bool isEmpty() {
      return (size == 0);
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
      q->pushBack(40);
      q->print();
      q->popBack();
      q->popBack();
      q->print();
      cout << endl;
   }
   return (0);
}
