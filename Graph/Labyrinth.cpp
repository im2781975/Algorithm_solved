//find a path from start to end. You can walk left, right, up and down. First print "YES", if there is a path, and "NO" otherwise.
//If there is a path, print the length of the shortest such path
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int MAX_N = 100;  // Adjust this according to the size of your labyrinth
const char WALL = '#';
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char moves[] = "RULD";
int n, m;
char labyrinth[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != WALL;
}
void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == end) {
            return; 
        }
        for (int i = 0; i < 4; i++) {
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];

            if (is_valid(new_x, new_y) && dist[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                dist[new_x][new_y] = dist[cur.first][cur.second] + 1;
                parent[new_x][new_y] = cur;
            }
        }
    }
}

string find_shortest_path(pair<int, int> start, pair<int, int> end) {
    if (dist[end.first][end.second] == -1) {
        return "NO";
    }
    string path;
    while (end != start) {
        pair<int, int> prev = parent[end.first][end.second];
        for (int i = 0; i < 4; i++) {
            int new_x = end.first + dx[i];
            int new_y = end.second + dy[i];
            if (new_x == prev.first && new_y == prev.second) {
                path = moves[i] + path;
                break;
            }
        }
        end = prev;
    }
    return "YES\n" + to_string(dist[start.first][start.second]) + "\n" + path;
}
int main() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            dist[i][j] = -1;
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    bfs(start, end);
    cout << find_shortest_path(start, end) << endl;
    return 0;
}
