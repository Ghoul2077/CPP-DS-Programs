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

      for (auto j : adj[i]) {
         cout << j << " ";
      }
      cout << endl;
   }
}

void addEdge(vector<int>adj[], int start, int stop) {
   adj[start].push_back(stop);
}

/**
 * @brief      Given a directed dependency graph we need to find safe sequence.
 *             The idea is to precompute indegree of all vertices and the use
 *             breadth first search where on every vertex we decrement the
 *             indegree of vertices it connected to and whichever vertex
 *             indegree turns 0 we push it in the queue. So the queue here
 *             contains all the vertices that can be processed as they have all
 *             dependencies cleared. This algorithm is also called kahn's
 *             algorithm. It's time complexity is O(V+E) and it's space
 *             complexity is O(V+E).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 * @param      indegree  Array containing indegree of all vertices
 */
void bfs(vector<int>adj[], int vertices, vector<int>& indegree) {
   queue<int> q;

   for (int i = 0; i < vertices; i++) {
      if (indegree[i] == 0) {
         q.push(i);
      }
   }

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      cout << curr << " ";

      for (auto i : adj[curr]) {
         indegree[i]--;

         if (indegree[i] == 0) {
            q.push(i);
         }
      }
   }
}

void printTopologicalSortingOfGivenDirectedGraph(vector<int>adj[],
                                                 int        vertices) {
   vector<int>  indegree(vertices, 0);
   vector<bool> visitedArr(vertices, false);

   for (int i = 0; i < vertices; i++) {
      for (auto j : adj[i]) {
         indegree[j]++;
      }
   }

   bfs(adj, vertices, indegree);
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

      printTopologicalSortingOfGivenDirectedGraph(adj, vertices);

      cout << endl;
   }
   return (0);
}
