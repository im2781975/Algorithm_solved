#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max();
// Function to find the shortest path using multistage graph
int multistage_shortest_path(vector<pair<int, unordered_map<int, int>>>& graph, 
    int source, int target, int k){
    // Initialize the shortest path distances
    vector<int> d(graph.size(), INF);
    d[target] = 0;
    // Loop over each stage from k-1 to 1
    for (int i = k - 1; i > 0; i--) {
        // Loop over all vertices in the current stage
        for (int v = 0; v < graph.size(); v++) {
            // Skip vertices not in the current stage
            if (graph[v].first != i) {
                continue;
            }
            // Update the shortest path distance of the current vertex
            for (const auto& u : graph[v].second) {
                d[v] = min(d[v], u.second + d[u.first]);
            }
        }
    }
    // Return the shortest path distance from source to target
    return d;
}
int main() {
    vector<pair<int, unordered_map<int, int>>> graph = {
        {0, {}},{1, {{3, 2}, {4, 9}}},
        {1, {{3, 6}, {4, 3}}},{2, {{4, 1}}},
        {2, {{5, 4}}},{3, {{5, 7}}},
        {3, {{6, 2}}},{4, {{5, 1}, {6, 5}}},
        {4, {{6, 6}}},{5, {}},{5, {}},{6, {}},{6, {}}};
    // Find the shortest path from vertex 0 to vertex 12
    int shortest_path_distance = multistage_shortest_path(graph, 0, 12, 7);
    cout << "Shortest path distance from vertex 0 to vertex 12: " << 
      shortest_path_distance << endl;
    return 0;
}
