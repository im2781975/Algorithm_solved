//There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
//Print the length of the shortest route for each query. If there is no route, print -1 instead
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
// Define a structure to represent the edges of the graph
struct Edge {
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Function to find the shortest route using Dijkstra's algorithm
vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int n, m, q;
    cin >> n >> m;

    // Create an adjacency list to represent the graph
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int source, destination;
        cin >> source >> destination;

        vector<int> distances = dijkstra(source, graph);
        int shortest_distance = distances[destination];

        if (shortest_distance == INF) {
            cout << -1 << endl;
        } else {
            cout << shortest_distance << endl;
        }
    }
    return 0;
}

