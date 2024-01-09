//The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.
//are allowed to pick an item any number of times.Find the maximum possible sum of the values of items that takes home
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int N, int W, vector<int>& weights, vector<int>& values) {
    vector<int> dp(W + 1, 0);

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < N; i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    return dp[W];
}
int main() {
    int N, W;
    cin >> N >> W;
    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }
    int result = knapsack(N, W, weights, values);
    cout << "Maximum value that can be carried in the knapsack: " << result ;
    return 0;
}
