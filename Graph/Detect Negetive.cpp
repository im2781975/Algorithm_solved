//You are given a directed graph, and your task is to find out if it contains a negative cycle.
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int source, destination, weight;
};
bool isNegativeCycle(int vertices, const vector<Edge>& edges) {
    vector<int> distance(vertices, INT_MAX);
    distance[0] = 0; 
    // Start from the first vertex
    for (int i = 0; i < vertices - 1; i++) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }
    for (const Edge& edge : edges) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            return true; 
            // Negative cycle found
        }
    }
    return false;
}
int main() {
    int vertices, edgesCount;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<Edge> edges(edgesCount);
    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }
    if (isNegativeCycle(vertices, edges)) {
        cout << "The graph contains a negative cycle." << endl;
    } else {
        cout << "The graph does not contain a negative cycle." << endl;
    }
    return 0;
}
