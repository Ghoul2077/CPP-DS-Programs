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
 * @brief      Given an undirected weighted graph find the minimum spanning tree.
 *             The idea is to use prim's algorithm where we do a breadth first
 *             search starting from 0th index and for each vertex we take the
 *             minimum weight edge that is adjacent to it. Rather than using
 *             traditional breadth first search here we use first loop to go
 *             through all the vertices and 2 loops inside of it where the first
 *             loop is used to pick up the next vertex that we add to our
 *             spanning tree and second loop to update the smallest edges
 *             connecting the vertices to the graph. The following implmentation
 *             uses iteration to pick the next vertex by finding the vertex with
 *             smallest edge not yet considered. This can be improved by using
 *             a priority queue (min heap). The time complexity of this method
 *             O(V*(V+E)) and it's space complexity is O(V).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 */
void primsAlgorithmForMinimumSpanningTree1(vector<pair<int, int> > *adj,
                                           int                      vertices) {
   vector<bool> visitedArr(vertices, false);
   vector<int>  shortestEdges(vertices, INT_MAX);

   shortestEdges[0] = 0;

   int minimumSpanningTreeCost = 0;

   for (int i = 0; i < vertices; ++i) {
      int currentVertex = -1;

      for (int j = 0; j < vertices; j++) {
         if ((visitedArr[j] == false) &&
             ((currentVertex == -1) ||
              (shortestEdges[j] < shortestEdges[currentVertex]))) {
            currentVertex = i;
         }
      }

      visitedArr[currentVertex] = true;
      minimumSpanningTreeCost  += shortestEdges[currentVertex];

      for (auto j : adj[currentVertex]) {
         if (visitedArr[j.first] == false) {
            shortestEdges[j.first] = min(shortestEdges[j.first], j.second);
         }
      }
   }

   cout << minimumSpanningTreeCost;
}

/**
 * @brief      This is the same algorithm as above just optimized using priority
 *             queue. By using min heap we are able to bring down it's time
 *             complexity to O((V+E)*logV).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 */
void primsAlgorithmForMinimumSpanningTree2(vector<pair<int, int> > *adj,
                                           int                      vertices) {
   vector<bool> visitedArr(vertices, false);
   priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,
                                                                        int> > >
   pq;

   pq.push({ 0, 0 });

   int minimumSpanningTreeCost = 0;

   for (int i = 0; i < vertices; ++i) {
      pair<int, int> nextVertex;

      while (!pq.empty()) {
         pair<int, int> curr = pq.top();
         pq.pop();

         if (visitedArr[curr.second] == false) {
            nextVertex = curr;
            break;
         }
      }

      visitedArr[nextVertex.second] = true;
      minimumSpanningTreeCost      += nextVertex.first;

      for (auto j : adj[nextVertex.second]) {
         if (visitedArr[j.first] == false) {
            pq.push({ j.second, j.first });
         }
      }
   }

   cout << minimumSpanningTreeCost;
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

      primsAlgorithmForMinimumSpanningTree2(adj, vertices);

      cout << endl;
   }
   return (0);
}
