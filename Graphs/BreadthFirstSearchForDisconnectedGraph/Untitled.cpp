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

void breadthFirstSearch(vector<int>adj[], int vertex,
                        vector<bool>& visitedArr) {
   queue<int> q;

   q.push(vertex);
   visitedArr[vertex] = true;

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      cout << curr << " ";

      for (auto i : adj[curr]) {
         if (!visitedArr[i]) {
            visitedArr[i] = true;
            q.push(i);
         }
      }
   }
}

/**
 * @brief      Breadth first search for disconnected graph. Unlinke a connected
 *             graph where we directly add nodes to a queue and then keep
 *             pushing and popping as they come, here we have some vertices that
 *             are not at all reachable by some of the other vertices hence we
 *             use the visited array to pick vertices for which we need to call
 *             breadth first search individually. In this case we keep a higher
 *             state of visited array and keep passing it to the bfs call, the
 *             changes made by which is used in the subsequent iterations of
 *             visited array. The time complexity of this method is O(V+E) and
 *             it's space complexity is O(V).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices of the graph
 */
void breadthFirstSearchDisconnectedGraph(vector<int>adj[], int vertices) {
   vector<bool> visitedArr(vertices, false);

   for (int i = 0; i < vertices; i++) {
      if (visitedArr[i] == false) {
         breadthFirstSearch(adj, i, visitedArr);
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

      breadthFirstSearchDisconnectedGraph(adj, vertices);
      cout << endl;
   }
   return (0);
}
