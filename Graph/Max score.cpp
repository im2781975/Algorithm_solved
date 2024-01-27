//You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
//Your task is to walk from room 1 to room n. What is the maximum score you can get?
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_N = 105;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> tunnels[MAX_N];
int dp[MAX_N][MAX_N];

int maxScore(int curRoom, int remainingRooms) {
    if (remainingRooms == 0) {
        if (curRoom == n) {
            return 0;
        } else {
            return -INF; // It's not possible to reach room n in the given number of moves.
        }
    }
    if (dp[curRoom][remainingRooms] != -1) {
        return dp[curRoom][remainingRooms];
    }
    int maxScore = -INF;
    for (auto tunnel : tunnels[curRoom]) {
        int nextRoom = tunnel.first;
        int score = tunnel.second;

        int result = maxScore(nextRoom, remainingRooms - 1);
        if (result != -INF) {
            maxScore = max(maxScore, result + score);
        }
    }
    return dp[curRoom][remainingRooms] = maxScore;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        tunnels[u].push_back({v, x});
    }
    memset(dp, -1, sizeof(dp));
    int result = maxScore(1, n);
    if (result == -INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
