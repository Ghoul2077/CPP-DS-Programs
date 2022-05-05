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

void dfs1(vector<int>   adj[],
          int           vertices,
          int           vertex,
          vector<int> & indegree,
          vector<bool>& visitedArr) {
   cout << vertex << " ";
   visitedArr[vertex] = true;

   for (auto i : adj[vertex]) {
      indegree[i]--;

      if (indegree[i] == 0) {
         dfs1(adj, vertices, i, indegree, visitedArr);
      }
   }
}

/**
 * @brief      Prints a topological sorting of given graph using depth first
 *             search. We try to modify the idea of indegree used to solve this
 *             problem with bfs. We use indegree array and perform dfs on the
 *             graph for each vertex which we have not yet visited and has 0
 *             indegree. For each vertex we process all it's adjacents and
 *             decrease their indegrees. We go to next level of reccursion only
 *             only if any adjacent vertices has 0 indegree. This way every
 *             reccursion call will have vertex with all indegree processed.
 *             It's time complexity is O(V+E) and it's space complexity is O(V+E)
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 */
void printTopologicalSortingUsingDFS1(vector<int>adj[], int vertices) {
   vector<int>  indegree(vertices, 0);
   vector<bool> visitedArr(vertices, false);

   for (int i = 0; i < vertices; i++) {
      for (auto j : adj[i]) {
         indegree[j]++;
      }
   }

   for (int i = 0; i < vertices; i++) {
      if ((visitedArr[i] == false) && (indegree[i] == 0)) {
         dfs1(adj, vertices, i, indegree, visitedArr);
      }
   }
}

void dfs2(vector<int>   adj[],
          int           vertices,
          int           vertex,
          vector<bool>& visitedArr,
          stack<int>  & st) {
   visitedArr[vertex] = true;

   for (auto i : adj[vertex]) {
      if (visitedArr[i] == false) {
         dfs2(adj, vertices, i, visitedArr, st);
      }
   }

   st.push(vertex);
}

/**
 * @brief      Prints a topological sorting of given graph using depth first
 *             search. The idea is to grasp that depth first search itself works
 *             in reverse of topological sorting. It usually visits the vertex
 *             with most indegree first and the the lesser one's. So with the
 *             use of stack we can get topological sorting from dfs. While
 *             exiting from current reccursion we push the vertex processed in
 *             this reccursion to the stack. Then after the dfs we just print
 *             contents of the stack. It's time complexity is O(V+E) and it's
 *             space complexity is O(V+E).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 */
void printTopologicalSortingUsingDFS2(vector<int>adj[], int vertices) {
   vector<bool> visitedArr(vertices, false);
   stack<int>   st;

   for (int i = 0; i < vertices; ++i) {
      if (visitedArr[i] == false) {
         dfs2(adj, vertices, i, visitedArr, st);
      }
   }

   while (!st.empty()) {
      int curr = st.top();
      st.pop();
      cout << curr << " ";
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

      printTopologicalSortingUsingDFS2(adj, vertices);

      cout << endl;
   }
   return (0);
}
