#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

class Queue {
private:
   int *queue;
   int front, rear;
   int capacity;

public:
   Queue(int size = 200) {
      queue    = new int[size];
      capacity = size;
      front    = -1;
      rear     = -1;
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
      if (front != -1) {
         int temp = front;

         while (temp != rear) {
            cout << queue[temp] << " ";
            temp = (temp + 1) % capacity;
         }

         cout << queue[rear] << endl;
      } else {
         cout << "Queue is empty" << endl;
      }
   }

   void enqueue(int data) {
      bool condition1 = (rear == front - 1);
      bool condition2 = (rear == capacity - 1) && front  == 0;

      if (condition1 && condition2) {
         cout << "Queue overflow" << endl;
      } else {
         if (front == -1) {
            front++;
         }
         rear        = (rear + 1) % capacity;
         queue[rear] = data;
      }
   }

   void dequeue()  {
      if (front != -1) {
         if (front == rear) {
            front = -1;
            rear  = -1;
         } else {
            front++;
            front %= capacity;
         }
      } else {
         cout << "Queue underflow" << endl;
      }
   }

   int getFront() {
      if (front != -1) {
         return (queue[front]);
      } else {
         cout << "Queue is empty" << endl;
         return (-1);
      }
   }

   int getRear() {
      if (rear != -1) {
         return (queue[rear]);
      } else {
         cout << "Queue is empty" << endl;
         return (-1);
      }
   }

   bool isFull()  {
      return ((front == rear + 1) || (front == 0 && rear == capacity - 1));
   }

   bool isEmpty() {
      return (front == -1);
   }
};

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      Queue *q = new Queue(5);
      q->initialize();
      q->print();
      q->dequeue();
      q->print();
      q->dequeue();
      q->print();
      q->dequeue();
      q->print();
      q->dequeue();
      q->print();
      q->dequeue();
      q->print();
      q->enqueue(22);
      q->print();
      cout << endl;
   }
   return (0);
}
