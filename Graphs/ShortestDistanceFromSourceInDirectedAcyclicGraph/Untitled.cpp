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
}

void kahnsAlgorithm(vector<pair<int, int> > *adj,
                    int                      vertices,
                    vector<int>            & distanceArr,
                    vector<int>              indegreeArr) {
   queue<int> q;

   for (int i = 0; i < vertices; i++) {
      if (indegreeArr[i] == 0) {
         q.push(i);
      }
   }

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (auto i : adj[curr]) {
         if (distanceArr[curr] != INT_MAX) {
            distanceArr[i.first] = min(distanceArr[i.first],
                                       distanceArr[curr] + i.second);
         }
         indegreeArr[i.first]--;

         if (indegreeArr[i.first] == 0) {
            q.push(i.first);
         }
      }
   }
}

/**
 * @brief      Finds the shortest distance from a given source vertex to all
 *             other verices. The idea is to understand that this is a kind of
 *             problem where we build from our previous solution i.e firstly the
 *             distance of our source from itself will always be 0 and all it's
 *             unreachable vertices will infinite so now we move in a topological
 *             fashion and compute the minimum distance which can be achieved by
 *             all vertices which are neighbour of these of the vertices we have
 *             already computed. By using topological sorting we are ensuring
 *             that the current vertex we are processing already has reached it's
 *             optimal shortest value from the source based on which we are
 *             finding further distances. It's time complexity is O(V+E) and it's
 *             space complexity is O(V+E). This method uses kahn's algorithm.
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 * @param[in]  source    The source vertex
 */
void shortestPathInWeightedDirectedGraph1(vector<pair<int, int> > *adj,
                                          int vertices, int source) {
   vector<bool> visistedArr(vertices, false);
   vector<int>  indegreeArr(vertices, 0);
   vector<int>  shortestDistanceArr(vertices, INT_MAX);

   shortestDistanceArr[source] = 0;

   for (int i = 0; i < vertices; ++i) {
      for (auto j : adj[i]) {
         indegreeArr[j.first]++;
      }
   }

   kahnsAlgorithm(adj, vertices, shortestDistanceArr, indegreeArr);

   for (int i = 0; i < vertices; i++) {
      if (shortestDistanceArr[i] == INT_MAX) {
         cout << "INF";
      } else {
         cout << shortestDistanceArr[i];
      }
      cout << " ";
   }
}

void dfs(vector<pair<int, int> > *adj,
         int                      source,
         vector<bool>           & visistedArr,
         stack<int>             & st) {
   visistedArr[source] = true;

   for (auto i : adj[source]) {
      if (visistedArr[i.first] == false) {
         dfs(adj, i.first, visistedArr, st);
      }
   }

   st.push(source);
}

/**
 * @brief      Finds the shortest distance from a given source vertex to all
 *             other verices. The idea is to understand that this is a kind of
 *             problem where we build from our previous solution i.e firstly the
 *             distance of our source from itself will always be 0 and all it's
 *             unreachable vertices will infinite so now we move in a topological
 *             fashion and compute the minimum distance which can be achieved by
 *             all vertices which are neighbour of these of the vertices we have
 *             already computed. By using topological sorting we are ensuring
 *             that the current vertex we are processing already has reached it's
 *             optimal shortest value from the source based on which we are
 *             finding further distances. It's time complexity is O(V+E) and it's
 *             space complexity is O(V+E). This method uses DFS method of
 *             topological sorting.
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 * @param[in]  source    The source vertex
 */
void shortestPathInWeightedDirectedGraph2(vector<pair<int, int> > *adj,
                                          int                      vertices,
                                          int                      source) {
   vector<int>  shortestDistanceArr(vertices, INT_MAX);
   vector<bool> visistedArr(vertices, false);
   stack<int>   st;

   for (int i = 0; i < vertices; i++) {
      if (visistedArr[i] == false) {
         dfs(adj, i, visistedArr, st);
      }
   }

   shortestDistanceArr[source] = 0;

   for (int i = 0; i < st.size(); i++) {
      int curr = st.top();
      st.pop();

      for (auto j : adj[curr]) {
         if (shortestDistanceArr[curr] != INT_MAX) {
            shortestDistanceArr[j.first] = min(shortestDistanceArr[j.first],
                                               shortestDistanceArr[curr] +
                                               j.second);
         }
      }
   }

   for (int i = 0; i < vertices; i++) {
      if (shortestDistanceArr[i] == INT_MAX) {
         cout << "INF";
      } else {
         cout << shortestDistanceArr[i];
      }
      cout << " ";
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

      shortestPathInWeightedDirectedGraph2(adj, vertices, source);

      cout << endl;
   }
   return (0);
}
