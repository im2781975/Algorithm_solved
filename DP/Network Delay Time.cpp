//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
//where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target We will send a signal from a given node k. 
//Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Create an adjacency list to represent the graph.
    vector<vector<pair<int, int>> graph(n + 1);  // +1 because node labels start from 1.

    for (const auto& edge : times) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        graph[u].push_back({v, w});
    }
    // Initialize a vector to store the minimum time it takes to reach each node from k.
    vector<int> dist(n + 1, numeric_limits<int>::max());

    // Create a priority queue to perform Dijkstra's algorithm.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node k with time 0.
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curTime = pq.top().first;
        pq.pop();

        // Explore neighbors of the current node.
        for (const auto& neighbor : graph[curNode]) {
            int nextNode = neighbor.first;
            int nextTime = neighbor.second;

            // Relaxation step.
            if (dist[curNode] + nextTime < dist[nextNode]) {
                dist[nextNode] = dist[curNode] + nextTime;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    int maxTime = *max_element(dist.begin() + 1, dist.end());  // Skip the 0th element.

    if (maxTime == numeric_limits<int>::max()) {
        return -1;  // Some nodes are not reachable.
    } else {
        return maxTime;
    }
}
int main() {
    int n = 5;
    int k = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int result = networkDelayTime(times, n, k);
    cout << "Minimum time to reach all nodes: " << result ;

    return 0;
}

