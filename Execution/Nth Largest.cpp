// K largest elements in an array
#include <bits/stdc++.h>
using namespace std;
// Function to find the Kth largest element in the array using binary search
int findKthLargest(int arr[], int n, int k)
{
    int low = INT_MAX, high = INT_MIN;
    // Find the minimum and maximum elements in the array
    for (int i = 0; i < n; i++) {
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }
    // Perform binary search on the range of elements between low and high
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        // Count the number of elements greater than mid in the array
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                count++;
            }
        }
        // If there are at least K elements greater than mid, search the right half
        if (count >= k) {
            low = mid + 1;
        }
        // Otherwise, search the left half
        else {
            high = mid - 1;
        }
    }
    // Return the Kth largest element
    return high;
}
// Function to print the K largest elements in the array
void printKLargest(int arr[], int n, int k)
{
    // Find the Kth largest element
    int kthLargest = findKthLargest(arr, n, k);
    // Print the K largest elements in decreasing order
    for (int i = 0; i < n; i++) {
        if (arr[i] >= kthLargest) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void kLargest(int arr[], int n, int k)
{
    // Sort the given array arr in reverse order.
    sort(arr, arr + n, greater<int>());
    // Print the first kth largest elements
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kLargest(arr, n, k);
}
