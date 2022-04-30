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
   adj[stop].push_back(start);
}

/**
 * @brief      Find whether there is a cycle in the given undirected graph. The
 *             idea is to check if we reach an already visited vertex during
 *             traversal. If yes then loop exists. The only thing to note here
 *             is the edge case where from parent vertex we visit the child
 *             vertex and then in the next iteration we visit the parent vertex
 *             from the child in this case it takes this also a cycle. So to
 *             overcome this edge case we check if the already visited vertex
 *             we encountered is the current vertex's parent or not and
 *             accordingly we take decision. How we implement it with breadth
 *             first search is that we keep a parent vertex array where we store
 *             parent vertex of each vertex and accordingly work on the algo.
 *             It's time complexity is O(V+E) and it's space complexity is
 *             O(V+E).
 *
 * @param      adj         The adjacency list
 * @param[in]  vertices    The count of vertices
 * @param[in]  vertex      The starting vertex
 * @param      visitedArr  The array of visited
 *
 * @return     True if cycle is found, false otherwise
 */
bool breadthFirstSearch(vector<int> adj[],
                        int         vertices,
                        int         vertex,
                        vector<bool>visitedArr) {
   queue<int> q;

   q.push(vertex);
   vector<int> parentArr(vertices, -1);

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      visitedArr[curr] = true;

      for (auto i : adj[curr]) {
         if (visitedArr[i] == false) {
            parentArr[i] = curr;
            q.push(i);
         } else if (i != parentArr[curr]) {
            return (true);
         }
      }
   }

   return (false);
}

/**
 * @brief      Find whether there is a cycle in the given undirected graph. The
 *             idea is to check if we reach an already visited vertex during
 *             traversal. If yes then loop exists. The only thing to note here
 *             is the edge case where from parent vertex we visit the child
 *             vertex and then in the next iteration we visit the parent vertex
 *             from the child in this case it takes this also a cycle. So to
 *             overcome this edge case we check if the already visited vertex
 *             we encountered is the current vertex's parent or not and
 *             accordingly we take decision. The time complexity of this method
 *             is O(V+E) and it's space complexity is O(V+E).
 *
 *
 * @param      adj         The adjacency list
 * @param[in]  vertex      The starting vertex
 * @param      visitedArr  The array of visited
 * @param[in]  parent      The parent of current vertex under consideration
 *
 * @return     True if cycle is found, false otherwise
 */
bool depthFirstSearch(vector<int>   adj[],
                      int           vertex,
                      vector<bool>& visitedArr,
                      int           parent = -1
                      ) {
   visitedArr[vertex] = true;

   for (auto i : adj[vertex]) {
      if (visitedArr[i] == false) {
         return (depthFirstSearch(adj, i, visitedArr, vertex));
      } else if (i != parent) {
         return (true);
      }
   }

   return (false);
}

bool detectCycleInUndirectedGraph(vector<int>adj[], int vertices) {
   vector<bool> visitedArr(vertices, false);
   bool isCycleDetected = false;

   for (int i = 0; i < vertices; i++) {
      if (visitedArr[i] == false) {
         // if (breadthFirstSearch(adj, vertices, i, visitedArr)) {
         //    return (true);
         // }
         if (depthFirstSearch(adj, i, visitedArr)) {
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

      bool cyclePresent = detectCycleInUndirectedGraph(adj, vertices);

      cout << (cyclePresent ? "True" : "False");

      cout << endl;
   }
   return (0);
}
