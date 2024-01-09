// On the way to the castle there lived many monsters. Each one of them had some gold coins. Although they are monsters they will not hurt. 
//Instead they will give you the gold coins, but if and only if you didn't take any coins from the monster directly before the current one.pass all the monsters and collect as many coins as possible. 
//Given the number of gold coins each monster has, calculate the maximum number of coins you can collect on your way to the castle. 
#include <iostream>
#include <vector>
using namespace std;

int maxGold(vector<int>& monsterGold) {
    int n = monsterGold.size();
    vector<long long> dp(n + 2, 0);

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(monsterGold[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        vector<int> monsterGold(n);

        for (int i = 0; i < n; i++) {
            cin >> monsterGold[i];
        }

        long long result = maxGold(monsterGold);
        cout << "Case " << test_case << ": " << result << endl;
    }

    return 0;
}
