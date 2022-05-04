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
}

/**
 * @brief      Given a directed graph we need to find cycle in the graph using
 *             kahn's algorithm. The idea is that kahn's algorithm is only valid
 *             for acyclic graph and thus using that as our deciding point we
 *             find what happens when it fails. We see that it comes out of the
 *             while loop when it reaches a cycle hence not traversing the
 *             remaining vertices part of the cycle. We can just count the
 *             number of vertices pushed to the queue by this algorithm, if it
 *             is equal to the number of vertices then we know there is no cycle
 *             otherwise there is a cycle. It's time complexity is O(V+E) and
 *             it's space complexity is O(V+E).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The count of vertices
 * @param      indegree  Array containing indegree of each vertex
 *
 * @return     True if cycle is present, false otherwise
 */
bool bfs(vector<int>adj[], int vertices, vector<int>& indegree) {
   int count = 0;
   queue<int> q;

   for (int i = 0; i < vertices; i++) {
      if (indegree[i] == 0) {
         count++;
         q.push(i);
      }
   }

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto i : adj[curr]) {
         indegree[i]--;

         if (indegree[i] == 0) {
            count++;
            q.push(i);
         }
      }
   }

   if (count != vertices) {
      return (true);
   }

   return (false);
}

void detectCycleInDirectedGraphKahnsAlgo(vector<int>adj[], int vertices) {
   vector<int> indegree(vertices, 0);

   for (int i = 0; i < vertices; ++i) {
      for (auto j : adj[i]) {
         indegree[j]++;
      }
   }

   bool isCyclePresent = bfs(adj, vertices, indegree);

   cout << (isCyclePresent ? "True" : "False");
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

      detectCycleInDirectedGraphKahnsAlgo(adj, vertices);

      cout << endl;
   }
   return (0);
}
