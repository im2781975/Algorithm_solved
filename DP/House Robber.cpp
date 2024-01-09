//Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that
//adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police. 
#include <vector>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> robHouse(n);
    vector<int> skipHouse(n);

    robHouse[0] = nums[0];
    skipHouse[0] = 0;

    for (int i = 1; i < n; ++i) {
        robHouse[i] = skipHouse[i - 1] + nums[i];
        skipHouse[i] = max(robHouse[i - 1], skipHouse[i - 1]);
    }
    return max(robHouse[n - 1], skipHouse[n - 1]);
}
int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    int maxAmount = rob(houses);

    cout << "Maximum amount that can be robbed: " << maxAmount ;
    return 0;
}
