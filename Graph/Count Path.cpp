//Bangladesh has n cities, and m roads between them.You can go from one city to another if there exists a path between those two cities.
//The goal is to  reach from city 1 to n.Print "YES" if your goal is possible, and "NO" otherwise
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1005;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
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
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    // Start DFS from city 1
    dfs(1);
    if (visited[n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
