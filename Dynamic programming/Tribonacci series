//All the problems below are related to Dynamic Programming. You have to solve each problem using both memoization and tabulation methods.

Write c++ code to output the n-th Tribonacci number. A Tribonacci series is a series where each number of the series is the sum of previous three numbers (except the 1st three numbers which are all 1-s)

The first few numbers of the series is as follows:

1, 1, 1, 3, 5, 9, 17, 31, 57, 105, 193, 355, 653, 1201 . . .
#include <iostream>
#include <vector>

// Using Memoization
std::vector<long long> memoization(100, -1);

long long tribonacciMemoization(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;
    if (memoization[n] != -1) return memoization[n];

    memoization[n] = tribonacciMemoization(n - 1) + tribonacciMemoization(n - 2) + tribonacciMemoization(n - 3);
    return memoization[n];
}

// Using Tabulation
long long tribonacciTabulation(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return 1;

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Using Memoization: " << tribonacciMemoization(n) << std::endl;
    std::cout << "Using Tabulation: " << tribonacciTabulation(n) << std::endl;

    return 0;
}

