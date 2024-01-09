//You are given an integer n.You can perform any of the following operations on  it as many times you want - Subtract 1 from it
//If it is divisible by 2 divide by 2. If it is divisible by 3 divide by 3.Find the minimum number of operations to make n=1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minOperations(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    return dp[n];
}
int main() {
    int n;
    cout << "Enter an integer n: ";
    cin >> n;

    int result = minOperations(n);
    cout << "Minimum number of operations to make n=1: " << result ;
    return 0;
}
