//There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Fill the diagonal with zeros (the distance from a city to itself is 0)
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    // Read the road lengths
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = w;
        // Assuming cities are 1-indexed
        dist[v - 1][u - 1] = w;
        // If roads are bidirectional
    }
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int src, dest;
        cin >> src >> dest;
        cout << "Shortest distance between city " << src << " and city " << dest << " is: ";
        if (dist[src - 1][dest - 1] != INF) {
            cout << dist[src - 1][dest - 1] << " units" << endl;
        } else {
            cout << "Not connected" << endl;
        }
    }
    return 0;
}

