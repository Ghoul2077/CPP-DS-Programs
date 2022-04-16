#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void printGraph(vector<int>adj[], int v) {
   for (int i = 0; i < v; i++) {
      for (auto x : adj[i]) {
         cout << x << " ";
      }
      cout << endl;
   }
}

void addEdge(vector<int>adj[], int u, int v) {
   adj[u].push_back(v);
   adj[v].push_back(u);
}

int main() {
   int v = 4, edges;

   cin >> edges;
   vector<int> adj[v];

   for (int i = 0; i < edges; i++) {
      int start, stop;
      cin >> start;
      cin >> stop;
      addEdge(adj, start, stop);
   }

   printGraph(adj, v);
   return (0);
}
