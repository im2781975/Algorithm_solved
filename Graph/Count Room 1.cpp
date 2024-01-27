//given a map of a building, and your task is to count the number of its rooms and the length of the longest room.
//The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
//length of the longest room means that room which contain maximum floor
#include <iostream>
#include <vector>
using namespace std;
int n, m;
// Define the possible movements (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfs(vector<vector<char>>& building, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || building[x][y] == '#') {
        return 0;
    }
    int size = 1;  
    // Count the current square as part of the room
    building[x][y] = '#';  
    // Mark the square as visited
    // Explore all possible directions
    for (int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        size += dfs(building, newX, newY);
    }
    return size;
}
int main() {
    cin >> n >> m;
    vector<vector<char>> building(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> building[i][j];
        }
    }
    int numRooms = 0;
    int longestRoom = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] == '.') {
                int roomSize = dfs(building, i, j);
                numRooms++;
                longestRoom = max(longestRoom, roomSize);
            }
        }
    }
    cout << numRooms << endl;
    cout << longestRoom << endl;
    return 0;
}
