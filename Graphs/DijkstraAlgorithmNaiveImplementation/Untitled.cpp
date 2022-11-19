#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void printGraph(const vector<vector<int> >& adj, int vertices) {
   for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }
}

void addEdge(vector<vector<int> >& adj, int start, int stop, int weight) {
   adj[start][stop] = weight;
   adj[stop][start] = weight;
}

/**
 * @brief      Naive implementation of dijkstra algorithm using adjacency matrix
 *             Check efficient implementation program for explanation of
 *             algorithm. The time complexity of this navie approach is O(V^2)
 *             and it's time complexity is O(V).
 *
 *             Note: Here we are running the loop only V - 1 times because at
 *             every traversal we fix adjacent vertices hence when we reach
 *             (V - 1)th vertex then we would have already fixed Vth vertex
 *             already.
 *
 * @param      adj       The adjacency matrix
 * @param[in]  vertices  The number of vertices
 * @param[in]  source    The source to find shortest path from
 */
void dijkstraAlgorithm(vector<vector<int> >& adj, int vertices, int source) {
   int res[vertices];

   fill(res, res + sizeof(res) / sizeof(int), INT_MAX);
   bool *visited = new bool[vertices];
   fill(visited, visited + vertices * sizeof(bool), false);

   res[source] = 0;

   for (int i = 0; i < vertices - 1; ++i) {
      int currVertex = -1;

      for (int j = 0; j < vertices; j++) {
         if ((visited[j] == false) &&
             ((currVertex == -1) || (res[j] < res[currVertex]))) {
            currVertex = j;
         }
      }

      visited[currVertex] = true;

      for (int j = 0; j < vertices; j++) {
         if (adj[currVertex][j] != INT_MAX) {
            res[j] = min(res[j], res[currVertex] + adj[currVertex][j]);
         }
      }
   }

   printArr(res, vertices);
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
      vector<vector<int> > adj(vertices, vector<int>(vertices, INT_MAX));

      for (int i = 0; i < vertices; ++i) {
         adj[i][i] = 0;
      }

      for (int i = 0; i < edges; i++) {
         int start, stop, weight;
         cin >> start;
         cin >> stop;
         cin >> weight;
         addEdge(adj, start, stop, weight);
      }

      int source;
      cin >> source;

      dijkstraAlgorithm(adj, vertices, source);

      cout << endl;
   }
   return (0);
}
