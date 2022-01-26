#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;

int main() {
   // Max heap priority queue
   priority_queue<int> pq1;

   // Min heap priority queue
   priority_queue<int, vector<int>, greater<int> > pq2;

   pq1.push(10);
   pq1.push(15);
   pq1.push(5);

   pq2.push(10);
   pq2.push(15);
   pq2.push(5);

   cout << pq1.size() << endl;
   cout << pq1.top() << endl;

   cout << "Max heap priority queue : ";

   while (!pq1.empty()) {
      cout << pq1.top() << " ";
      pq1.pop();
   }

   cout << endl;

   cout << "Min heap priority queue : ";

   while (!pq2.empty()) {
      cout << pq2.top() << " ";
      pq2.pop();
   }

   return (0);
}
