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

void breadthFirstSearch(vector<int>adj[], int vertex,
                        vector<bool>& visitedArr) {
   queue<int> q;

   q.push(vertex);
   visitedArr[vertex] = true;

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto i : adj[curr]) {
         if (!visitedArr[i]) {
            visitedArr[i] = true;
            q.push(i);
         }
      }
   }
}

/**
 * @brief      Counts the number of disconnected components in a given graph.
 *             The idea is to use BFS search. BFS search has the quality that
 *             if a set of vertices are connected then in a single BFS traversal
 *             you will visit all of them. So if after one traversal if there
 *             are any vertices left unvisited you increment count and call BFS
 *             on that unvisited vertex, we continue this until we have visited
 *             all the vertices. It's time complexity is O(V+E) and it's space
 *             complexity is O(V).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The count of vertices
 *
 * @return     count of disconnected components in graph.
 */
int countDisconnectedComponentsInGraph(vector<int>adj[], int vertices) {
   int disconnectedComponentCount = 0;
   vector<bool> visitedArr(vertices, false);

   for (int i = 0; i < vertices; i++) {
      if (visitedArr[i] == false) {
         disconnectedComponentCount++;
         breadthFirstSearch(adj, i, visitedArr);
      }
   }

   return (disconnectedComponentCount);
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

      cout << countDisconnectedComponentsInGraph(adj, vertices);
      cout << endl;
   }
   return (0);
}
