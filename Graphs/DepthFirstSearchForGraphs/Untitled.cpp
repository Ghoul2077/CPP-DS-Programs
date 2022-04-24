#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void printGraph(vector<int>adj[], int vertices) {
   for (int i = 0; i < vertices; i++) {
      cout << i << " : ";

      for (auto j : adj[vertices]) {
         cout << j << " ";
      }
      cout << endl;
   }
}

void addEdge(vector<int>adj[], int start, int stop) {
   adj[start].push_back(stop);
   adj[stop].push_back(start);
}

void depthFirstSearch(vector<int>adj[], int vertex,
                      vector<bool>& visitedArr) {
   cout << vertex << " ";
   visitedArr[vertex] = true;

   for (auto i : adj[vertex]) {
      if (!visitedArr[i]) {
         depthFirstSearch(adj, i, visitedArr);
      }
   }
}

/**
 * @brief      In depth first search traversal unlike breadth first search we
 *             traverse the graph reccursivly. At each reccursive call we print
 *             the current reached vertex and then proceed to visit it's
 *             adjacency list reccursivly. We keep doing this until all the
 *             vertices are visited. It's time complexity is O(V+E) and it's
 *             space complexity is O(V). We can also replace reccursion with
 *             stack in DFS.
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The count of vertices
 */
void depthFirstSearchMain(vector<int>adj[], int vertices) {
   vector<bool> visitedArr(vertices, false);

   // Below statement will suffice if the graph is connected
   // depthFirstSearch(adj, 0, visitedArr);

   for (int i = 0; i < vertices; i++) {
      if (!visitedArr[i]) {
         depthFirstSearch(adj, i, visitedArr);
      }
   }
}

int main() {
   int testCases;

   srand(time(0));
   cin >> testCases;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < testCases; i++) {
      int edges, vertices;
      cin >> vertices;
      cin >> edges;
      vector<int> adj[vertices];

      for (int i = 0; i < edges; i++) {
         int start, stop;
         cin >> start;
         cin >> stop;
         addEdge(adj, start, stop);
      }

      depthFirstSearchMain(adj, vertices);

      cout << endl;
   }
   return (0);
}
