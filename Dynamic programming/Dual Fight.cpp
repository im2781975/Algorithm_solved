// found the information about all the dual fights. Dual fight means a fight between a Lykan and a Vampire. They know the name of the dual fighters,
//but don't know which one of them is a Vampire or a Lykan.So, the humans listed all the rivals. They want to find the maximum possible number of Vampires or Lykans.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200;  
// Maximum number of fighters
vector<int> adj[MAXN];  
// Adjacency list to represent the graph
int match[MAXN];       
// Matched fighters
// Function to add an edge between a fighter and a dual fighter
void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Function to perform DFS and find augmenting paths in the graph
bool dfs(int u) {
    for (int v : adj[u]) {
        if (match[v] == -1 || (match[v] != u && dfs(match[v]))) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
// Function to find the maximum number of vampires or lykans
int maxVampiresOrLykans(int n) {
    fill(match, match + n, -1);
    int maxMatches = 0;

    for (int i = 0; i < n; i++) {
        if (match[i] == -1 && dfs(i)) {
            maxMatches++;
        }
    }
    return maxMatches;
}
int main() {
    int n;  
    // Number of dual fights
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        // Assuming u and v are 0-based indices, and u is a Lykan, v is a Vampire
        addEdge(u, v);
    }
    int maxVampiresOrLykans = maxVampiresOrLykans(2 * n);  // Assuming there are 2 fighters per dual fight

    cout << "The maximum possible number of Vampires or Lykans: " << maxVampiresOrLykans << endl;
    return 0;
}
