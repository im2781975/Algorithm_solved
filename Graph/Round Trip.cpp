// design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
//First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited.
//If there are no solutions, print "IMPOSSIBLE".
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1005; // Adjust this according to the maximum number of cities

vector<int> adj[MAX_N];
vector<int> route;
bool visited[MAX_N];

void dfs(int node) {
    visited[node] = true;
    route.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        } else if (route.size() > 2 && neighbor == route[0]) {
            // If we have visited at least 2 cities and can return to the starting city
            return;
        }
    }
    route.pop_back();
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        // Try starting the route from each city
        route.clear();
        fill(visited, visited + n + 1, false);
        dfs(i);
        if (route.size() >= 3) {
            cout << route.size() << "\n";
            for (int city : route) {
                cout << city << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

