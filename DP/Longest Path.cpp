//There is a directed graph G with N vertices & M edges. The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), the i-th directed edge goes from Vertex xi to yi.G does not contain directed cycles.directed path in G. Here, the length of a directed path is the number of edges in it.
//Find the length of the longest directed path in G. Here, the length of a directed path is the number of edges in it.
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN];
// Adjacency list representation of the graph
int dp[MAXN]; 
// DP array to store the longest path ending at vertex i

int dfs(int v) {
    if (dp[v] != -1) {
        return dp[v];
    }
    int maxPath = 0;
    for (int u : adj[v]) {
        maxPath = max(maxPath, dfs(u) + 1);
    }
    return dp[v] = maxPath;
}
int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    fill(dp, dp + N + 1, -1);
    int longestPath = 0;
    for (int i = 1; i <= N; i++) {
        longestPath = max(longestPath, dfs(i));
    }

    cout << "Length of the longest directed path: " << longestPath ;
    return 0;
}
