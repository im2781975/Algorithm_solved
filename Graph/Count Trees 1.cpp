#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// define a pair to represent a node in the forest
typedef pair<int, int> Node;
// function to perform BFS from a given node and mark all visited nodes
void bfs(vector<vector<int>>& forest, Node start, vector<vector<bool>>& visited) {
    // create a queue for BFS
    queue<Node> q;
    q.push(start);
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
 
        // add unvisited neighboring nodes to the queue
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (nx >= 0 && nx < forest.size() && ny >= 0 && ny < forest[0].size() && forest[nx][ny] == 1 && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}
// function to count the number of trees in a forest using BFS
int count_trees_in_forest(vector<vector<int>>& forest) {
    int count = 0;
    int n = forest.size();
    int m = forest[0].size();
    // create a 2D boolean array to keep track of visited nodes
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // iterate over all nodes in the forest and perform BFS from each unvisited tree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (forest[i][j] == 1 && !visited[i][j]) {
                bfs(forest, make_pair(i, j), visited);
                count++;
            }
        }
    }
    return count;
}
int main() {
    vector<vector<int>> forest = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int num_trees = count_trees_in_forest(forest);
    cout << "The forest has " << num_trees << " trees." << endl;
    return 0;
}
