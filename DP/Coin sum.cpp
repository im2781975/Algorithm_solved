//You have n coins with certain values. Your task is to find all money sums you can create using these coins.
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findMoneySums(vector<int>& coins, int n) {
    set<int> sums;
    sums.insert(0);

    for (int i = 0; i < n; i++) {
        vector<int> newSums;
        for (int sum : sums) {
            newSums.push_back(sum + coins[i]);
        }
        sums.insert(newSums.begin(), newSums.end());
    }

    for (int sum : sums) {
        cout << sum << " ";
    }
}
int main() {
    vector<int> coins = {1, 2, 5};
    int n = coins.size();
    findMoneySums(coins, n);
    return 0;
}
