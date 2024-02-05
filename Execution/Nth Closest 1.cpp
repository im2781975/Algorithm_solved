#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    // Create a max heap to store the pairs of absolute differences and negative values
    priority_queue<pair<int, int> > maxH;
 
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        // Skip if the element is equal to x
        if (arr[i] == x)
            continue;
        // Calculate the absolute difference and add the pair to the max heap
        maxH.push({ abs(arr[i] - x), -arr[i] });
 
        // If the size of the max heap exceeds k, remove the element with the maximum absolute difference
        if (maxH.size() > k)
            maxH.pop();
    }
    // Store the result in a vector
    vector<int> result;
    // Retrieve the top k elements from the max heap
    while (!maxH.empty()) {
        // Get the top element from the max heap
        auto p = maxH.top();
        maxH.pop();
        // Add the negative value to the result vector
        result.push_back(-p.second);
    }
    // Reverse the result vector to get the closest numbers in ascending order
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    vector<int> arr = { 12, 16, 22, 30, 35, 39, 42,
    45, 48, 50, 53, 55, 56 };
    int k = 4, x = 35;
    vector<int> res = findClosestElements(arr, k, x);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
