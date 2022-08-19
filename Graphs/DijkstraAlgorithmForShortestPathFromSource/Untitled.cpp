#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << # x << " = " << x << endl;
#define deb2(x, \
             y) cout << # x << " = " << x << ", " << # y << " = " << y << endl;
#define printArr(arr, size) cout << # arr << " : "; \
   for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;


void printGraph(vector<pair<int, int> > *adj, int vertices) {
   for (int i = 0; i < vertices; i++) {
      cout << i << " : " << endl;

      for (auto j : adj[i]) {
         cout << "Vertex : " << j.first << " Weight : " << j.second;
      }
      cout << endl;
   }
}

void addEdge(vector<pair<int, int> > *adj, int start, int stop, int weight) {
   adj[start].push_back({ stop, weight });
   adj[stop].push_back({ start, weight });
}

/**
 * @brief      Breadth first search for dijkstra's algorithm. The idea here is
 *             to keep 2 arrays, one where we store which all vertices have
 *             shortest distance from source finalized and another where we
 *             store the weight of the shortest paths. Next we start with our
 *             source and then follow with breadth first search filling the
 *             shortest distance array value with immediate values that the
 *             adjacent edge provides, for next iteration we choose the vertex
 *             with the smallest weight from the shortest distance array which
 *             we have yet to traverse and follow it's adjacent and fill
 *             shortest distance array with smaller values if any. This method
 *             works on the fact that it treats the smallest adjacent edge as
 *             a definite edge in our shortest path and builds solution on that.
 *             The time complexity of this solution is O((V+E)*N) and it's space
 *             complexity is O(V).
 *
 * @param      adj                The adjacency list
 * @param[in]  source             The source to find shortest path from
 * @param      visitedArr         The array containing vertices visited already
 * @param      shortestDistances  The array storing shortest distances from source
 */
void bfs(vector<pair<int, int> > *adj,
         int                      source,
         vector<bool>           & visitedArr,
         vector<int>            & shortestDistances) {
   queue<int> q;

   q.push(source);

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      visitedArr[curr] = true;

      for (auto i : adj[curr]) {
         int vertex = i.first;
         int weight = i.second;

         if (shortestDistances[curr] != INT_MAX) {
            shortestDistances[vertex] = min(shortestDistances[vertex],
                                            shortestDistances[curr] +
                                            weight);
         }
      }

      int nextVertex = -1;

      for (int i = 0; i < shortestDistances.size(); i++) {
         if (!visitedArr[i] &&
             ((nextVertex == -1) ||
              (shortestDistances[i] < shortestDistances[nextVertex]))) {
            nextVertex = i;
         }
      }

      if (nextVertex != -1) {
         q.push(nextVertex);
      }
   }
}

/**
 * @brief      This is modified breadth first search for dijkstra's algorithm.
 *             It makes use of the capabilities of priority queue to bring the
 *             time complexity of searching for smallest value down from N to
 *             logN. It uses another fact that we only add to the priority queue
 *             when actually hit any path smaller than the path we already know.
 *             What this does is it prioritises the result and once result is
 *             reached then only the redundant values in the priority queue will
 *             be traversed even though they would not have any effect on the
 *             result. It's time complexity is O((V+E)*logV) and it's space
 *             complexity is O(V).
 *
 * @param      adj                The adjacency list
 * @param[in]  source             The source to find shortest path from
 * @param      shortestDistances  The array storing shortest distances from source
 */
void bfsModified(vector<pair<int, int> > *adj,
                 int                      source,
                 vector<int>            & shortestDistances) {
   priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,
                                                                        int> > >
   pq;

   pq.push({ 0, source });

   while (!pq.empty()) {
      int curr = pq.top().second;
      pq.pop();

      for (auto i : adj[curr]) {
         int vertex = i.first;
         int weight = i.second;

         if (shortestDistances[vertex] > shortestDistances[curr] + weight) {
            shortestDistances[vertex] = shortestDistances[curr] + weight;
            pq.push({ shortestDistances[vertex], vertex });
         }
      }
   }
}

/**
 * @brief      Implementation of dijkstra algorithm using breadth first search.
 *             Dijkstra algorithm is bound to fail for negative edges therefore
 *             need to take care that the input edges are positive only.
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 * @param[in]  source    The source to find shortest path from
 */
void shortestPathUndirectedGraph(vector<pair<int, int> > *adj,
                                 int                      vertices,
                                 int                      source) {
   vector<bool> visitedArr(vertices, false);
   vector<int>  shortestDistances(vertices, INT_MAX);

   shortestDistances[source] = 0;

   // bfs(adj, source, visitedArr, shortestDistances);
   bfsModified(adj, source, shortestDistances);

   printArr(shortestDistances, vertices);
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
      vector<pair<int, int> > adj[vertices];

      for (int i = 0; i < edges; i++) {
         int start, stop, weight;
         cin >> start;
         cin >> stop;
         cin >> weight;
         addEdge(adj, start, stop, weight);
      }

      int source;
      cin >> source;

      shortestPathUndirectedGraph(adj, vertices, source);

      cout << endl;
   }
   return (0);
}
