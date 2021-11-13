#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class Queue {
private:
   list<int>queue;
   int capacity;

public:
   Queue(int size = 300) {
      capacity = size;
   }

   void initialize() {
      int val;

      cin >> val;

      while (val != -1) {
         enqueue(val);
         cin >> val;
      }
   }

   void print() {
      if (isEmpty()) {
         cout << "Queue is empty" << endl;
         return;
      }

      for (auto i : queue) {
         cout << i << " ";
      }
      cout << endl;
   }

   void enqueue(int data) {
      if (queue.size() != capacity) {
         queue.push_back(data);
      } else {
         cout << "Queue overflow" << endl;
      }
   }

   void dequeue() {
      if (queue.size() != 0) {
         queue.erase(queue.begin());
      } else {
         cout << "Queue underflow" << endl;
      }
   }

   int getFront() {
      if (queue.size() != 0) {
         return (queue.front());
      } else {
         cout << "Queue is empty" << endl;
         return (-1);
      }
   }

   int getRear() {
      if (queue.size() != 0) {
         return (queue.back());
      } else {
         cout << "Queue is empty" << endl;
         return (-1);
      }
   }

   bool isFull() {
      return (queue.size() == capacity);
   }

   bool isEmpty() {
      return (queue.size() == 0);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Queue *q = new Queue();
      q->initialize();
      q->dequeue();
      q->print();
      cout << endl;
   }
   return (0);
}
