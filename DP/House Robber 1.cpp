// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
//Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    // Rob the first house and exclude the last house
    int robFirst = robRange(nums, 0, n - 2);
    // Rob the last house and exclude the first house
    int robLast = robRange(nums, 1, n - 1);
    
    // Take the maximum of the two scenarios
    return max(robFirst, robLast);
}
int robRange(vector<int>& nums, int start, int end) {
    int prev1 = 0;  
    // Represents the maximum money that can be robbed with the current house included
    int prev2 = 0; 
    // Represents the maximum money that can be robbed without the current house
    for (int i = start; i <= end; i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int main() {
    vector<int> houses = {2, 7, 9, 3, 1};
    int result = rob(houses);

    cout << "Maximum amount that can be robbed: " << result ;
    return 0;
}

