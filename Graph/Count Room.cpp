//given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, 
//and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
#include <iostream>
#include <vector>
using namespace std;
// Define directions for moving: up, down, left, right
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
// Function to perform DFS to count rooms
void dfs(int x, int y, vector<vector<char>>& map, vector<vector<bool>>& visited) {
    int n = map.size();
    int m = map[0].size();

    visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny, map, visited);
        }
    }
}
// Function to count rooms in the building map
int countRooms(vector<vector<char>>& map) {
    int n = map.size();
    int m = map[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !visited[i][j]) {
                // Start a new room and perform DFS
                dfs(i, j, map, visited);
                roomCount++;
            }
        }
    }
    return roomCount;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    int roomCount = countRooms(map);
    cout << "Number of rooms: " << roomCount << endl;
    return 0;
}

