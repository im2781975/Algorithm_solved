//Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
//If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route and path.print all valid solution.
//If there are no routes, print "IMPOSSIBLE".
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1005;  
// Maximum number of computers
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> path;
bool found = false;
void dfs(int u, int destination) {
    if (found) return;
    visited[u] = true;
    path.push_back(u);

    if (u == destination) {
        found = true;
        cout << path.size() << " ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, destination);
        }
    }
    path.pop_back();
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    // Build the graph
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int Uolevi, Maija;
    cin >> Uolevi >> Maija;
    dfs(Uolevi, Maija);
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

