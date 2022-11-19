#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int bigInt;
#define mod 1000000007;
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define printArr(arr, size)                               \
    cout << #arr << " : ";                                \
    for (int i = 0; i < size; i++) cout << arr[i] << " "; \
    cout << endl;

void printGraph(vector<pair<int, int>> *adj, int vertices) {
    for (int i = 0; i < vertices; i++) {
        cout << i << " : " << endl;

        for (auto j : adj[i]) {
            cout << "vertex : " << j.first << " weight : " << j.second;
        }
        cout << endl;
    }
}

void addEdge(vector<pair<int, int>> *adj, int start, int stop, int weight) {
    adj[start].push_back({stop, weight});
    adj[stop].push_back({start, weight});
}

/**
 * @brief      Bellman ford algorithm is a shortest path algorithm which works
 *             for directed graph but with no negative cycles and undirected
 *             graph with no negative edges. The idea is to use concept of
 *             dynamic programming, in a bottom up order we start finding the
 *             smallest 1 edge length distance from source to all other vertex,
 *             then from that 1 edge length distances we find 2 edge length
 *             distances to all other vertices and so on until we cover v - 1
 *             edge length distance. During this process we keep comparing
 *             every new distance with our previous smallest distance and update
 *             the shortest distance if the newly calculated one is smaller than
 *             the previous one we had. At the end of this loop we are bound
 *             to have smallest distances to all vertices from source.
 *             Note :- To find if the graph has any negative cycles we need just
 *             an additional step to the above one i.e calculate V edge
 *             distances and if your result is changed from before it is a proof
 *             that there is a negative cycle in the graph.
 *             The time complexity of this algorithm is O(V*E) and it's space
 *             complexity is O(V). Even though it is slower than djikstra it is
 *             more prominently used because of it's simple nature and it's
 *             ability to handle negative edges.
 *
 * @param      adj       The adjacency list
 * @param[in]  vertices  The number of vertices
 * @param[in]  source    The source of shortest path
 */
void bellmanFord(vector<pair<int, int>> *adj, int vertices, int source) {
    vector<int> shortestDistance(vertices, INT_MAX);
    shortestDistance[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < vertices; ++j) {
            for (auto k : adj[j]) {
                if (shortestDistance[j] != INT_MAX) {
                    shortestDistance[k.first] =
                        min(shortestDistance[k.first],
                            shortestDistance[j] + k.second);
                }
            }
        }
    }

    printArr(shortestDistance, vertices);
}

int main() {
    int testCases;

    srand(time(0));
    cin >> testCases;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < testCases; i++) {
        int edges, vertices, source;
        cin >> vertices;
        cin >> edges;
        vector<pair<int, int>> adj[vertices];

        for (int i = 0; i < edges; i++) {
            int start, stop, weight;
            cin >> start;
            cin >> stop;
            cin >> weight;
            addEdge(adj, start, stop, weight);
        }

        cin >> source;

        bellmanFord(adj, vertices, source);

        cout << endl;
    }
    return (0);
}
