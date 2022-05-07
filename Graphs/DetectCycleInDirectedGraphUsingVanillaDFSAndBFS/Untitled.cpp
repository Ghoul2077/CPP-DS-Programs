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
 * @brief      Find cycle in a given directed graph. The idea is to use depth
 *             first search and keep storing all the vertices that are part of
 *             the current reccursive call in an array and whenever we reach
 *             a vertex that we have already visited then we check if that
 *             already visited vertex is part of the current reccusion path or
 *             not, if yes then we have a cycle else we move on to other by
 *             picking up another reccursive path. It's time complexity is
 *             O(V+E) and it's space complexity is O(V+E).
 *
 *
 * @param      adj                 The adjacency list
 * @param[in]  vertex              The starting vertex
 * @param      visitedArr          The visited vertex arr
 * @param      reccursionStackArr  The array to store current vertex part of reccursion
 *
 * @return     { description_of_the_return_value }
 */
bool depthFirstSearch(vector<int>   adj[],
                      int           vertex,
                      vector<bool>& visitedArr,
                      vector<bool>& reccursionStackArr) {
   visitedArr[vertex]         = true;
   reccursionStackArr[vertex] = true;

   for (auto i : adj[vertex]) {
      if (visitedArr[i] == false) {
         if (depthFirstSearch(adj, i, visitedArr, reccursionStackArr)) {
            return (true);
         }
      } else if (reccursionStackArr[i] == true) {
         return (true);
      }
   }

   reccursionStackArr[vertex] = false;

   return (false);
}

bool detectCycleInDirectedGraph(vector<int>adj[], int vertices) {
   vector<bool> visitedArr(vertices, false);
   vector<bool> reccursionStackArr(vertices, false);

   for (int i = 0; i < vertices; i++) {
      if (visitedArr[i] == false) {
         if (depthFirstSearch(adj, i, visitedArr, reccursionStackArr)) {
            return (true);
         }
      }
   }

   return (false);
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

      bool isCyclePresent = detectCycleInDirectedGraph(adj, vertices);

      cout << (isCyclePresent ? "True" : "False");

      cout << endl;
   }
   return (0);
}
