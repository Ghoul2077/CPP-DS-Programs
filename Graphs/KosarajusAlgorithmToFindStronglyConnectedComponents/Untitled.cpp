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
   for (int i = 0; i < vertices; i++) {
      cout << i << " : ";

      for (int j = 0; j < vertices; j++) {
         cout << adj[i][j] << " ";
      }
      cout << endl;
   }
}

void dfs(const vector<vector<int> >& adj,
         int                         source,
         int                         vertices,
         vector<bool>              & visitedArr,
         stack<int>                & st) {
   visitedArr[source] = true;

   for (int i = 0; i < vertices; i++) {
      if ((visitedArr[i] == false) && (adj[source][i] == 1)) {
         dfs(adj, i, vertices, visitedArr, st);
      }
   }

   st.push(source);
}

void printLoop(const vector<vector<int> >& adj,
               int                         source,
               int                         vertices,
               vector<bool>              & visitedArr) {
   cout << source << " ";
   visitedArr[source] = true;

   for (int i = 0; i < vertices; i++) {
      if ((visitedArr[i] == false) && (adj[source][i] == 1)) {
         printLoop(adj, i, vertices, visitedArr);
      }
   }
}

void transpose(vector<vector<int> >& adj, int vertices) {
   for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
         if (i < j) {
            swap(adj[i][j], adj[j][i]);
         }
      }
   }
}

/**
 * @brief      Finds strongly connected vertices using kosaraju's algorithm.
 *             This is a tricky algorithm to think, the idea is to find the
 *             order in which the processing of each vertex is completed after
 *             which we reverse all the edges of the graph and then based on the
 *             order of processing we found earlier we traverse this reversed
 *             graph and print the dfs of each vertex. This method allows us to
 *             print the strongly connected components in seperate lines. Here
 *             the reversal of the graph ensures that we only traverse strongly
 *             connected components as whether you take original graph or the
 *             newly reversed one in both the strongly connected components will
 *             remain strongly connected only. The time complexity of this
 *             algorithm is O(V^2) and it's space complexity is O(V). The time
 *             complexity can be improved to O(V+E) if we use adjacency list and
 *             use extra space to create a new reversed adjacecy list.
 *
 * @param      adj       The adjacency matrix
 * @param[in]  vertices  The number of vertices
 */
void findStronglyConnectedVertices(vector<vector<int> >& adj, int vertices) {
   vector<bool> visitedArr(vertices, false);
   stack<int>   st;

   for (int i = 0; i < vertices; i++) {
      if (visitedArr[i] == false) {
         dfs(adj, 0, vertices, visitedArr, st);
      }
   }

   transpose(adj, vertices);

   fill(visitedArr.begin(), visitedArr.end(), false);

   while (!st.empty()) {
      int curr = st.top();
      st.pop();

      if (visitedArr[curr] == false) {
         printLoop(adj, curr, vertices, visitedArr);
         cout << endl;
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
      vector<vector<int> > adj(vertices, vector<int>(vertices, 0));

      for (int i = 0; i < edges; i++) {
         int start, stop;
         cin >> start;
         cin >> stop;
         adj[start][stop] = 1;
      }

      findStronglyConnectedVertices(adj, vertices);

      cout << endl;
   }
   return (0);
}
