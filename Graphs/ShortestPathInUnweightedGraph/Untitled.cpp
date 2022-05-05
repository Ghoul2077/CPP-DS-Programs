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
   adj[stop].push_back(start);
}

void breadthFirstSearch(vector<int>  adj[],
                        int          source,
                        int          vertices,
                        vector<int>& distanceArr) {
   vector<bool> visitedArr(vertices, false);

   visitedArr[source] = true;
   queue<int> q;

   q.push(source);

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto i : adj[curr]) {
         if (visitedArr[i] == false) {
            distanceArr[i] = distanceArr[curr] + 1;
            visitedArr[i]  = true;
            q.push(i);
         }
      }
   }
}

/**
 * @brief      Find the shortest path from a given source vertex to every other
 *             vertex in a unweighted graph. The idea is to use breadth first
 *             search where we search each level for a given vertex if not
 *             visited before, we know if this is our first encounter of the
 *             vertex then it is the shortest path and we won't try finding
 *             any more path for that vertex. It's time complexity is O(V+E) and
 *             it's space complexity is O(V).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The count of vertices
 * @param[in]  source    The source to find shortests paths from
 */
void shortestPathInUnweightedGraph(vector<int>adj[], int vertices,
                                   int source = 0) {
   vector<int> distanceArr(vertices, INT_MAX);

   distanceArr[source] = 0;

   breadthFirstSearch(adj, source, vertices, distanceArr);

   for (auto i : distanceArr) {
      cout << i << " ";
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

      shortestPathInUnweightedGraph(adj, vertices);

      cout << endl;
   }
   return (0);
}
