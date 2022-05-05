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

/**
 * @brief      Breadth first search is one where we pick up one node / vertex
 *             and then we keep visiting it's adjacent vertices and then their
 *             adjacent vertices in first come first serve order. It's similar
 *             to level order traversal in binary tree just the fact that in
 *             graph we can reach a vertex more than once hence to incorporate
 *             that fact we keep a visited array where we keep track if we have
 *             visited ith vertex or not. It's time complexity is O(V) and it's
 *             space compelxity is O(V).
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The count of vertices
 */
void breadthFirstSearch(vector<int>adj[], int vertices) {
   bool *visitedArr = new bool[vertices];

   fill(visitedArr, visitedArr + vertices, false);

   queue<int> q;

   q.push(0);
   visitedArr[0] = true;

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

      breadthFirstSearch(adj, vertices);
      cout << endl;
   }
   return (0);
}
