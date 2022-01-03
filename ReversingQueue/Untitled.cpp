#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;

void print(queue<int>q) {
   queue<int> copyQueue = q;

   while (!copyQueue.empty()) {
      cout << copyQueue.front() << " ";
      copyQueue.pop();
   }
   cout << endl;
}

void reverseQueueReccursive(queue<int>& q) {
   if (q.empty()) {
      return;
   }

   int curr = q.front();

   q.pop();
   reverseQueueReccursive(q);
   q.push(curr);
}

void reverseQueue(queue<int>& q) {
   stack<int> st;

   while (!q.empty()) {
      st.push(q.front());
      q.pop();
   }

   while (!st.empty()) {
      q.push(st.top());
      st.pop();
   }
}

int main() {
   int testCases;

   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      queue<int> q;
      int val;
      cin >> val;

      while (val != -1) {
         q.push(val);
         cin >> val;
      }

      print(q);
      reverseQueue(q);
      print(q);

      cout << endl;
   }
   return (0);
}
