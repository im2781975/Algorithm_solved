//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x 
#include <iostream>
#include <vector>
using namespace std;
int countWays(vector<int>& coins, int n, int x) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= x; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[x];
}
int main() {
    int n; // Number of coins
    int x; // Money sum to produce
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << "Enter the money sum (x): ";
    cin >> x;

    int ways = countWays(coins, n, x);
    cout << "Number of distinct ways to make " << x << " using the given coins: " << ways ;
    return 0;
}
