#include <bits/stdc++.h>
using namespace std;
// returns true if arr[0..n-1] has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
    // Find the pivot element
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;
    // l is now index of smallest element
    int l = (i + 1) % n;
    // r is now index of largest element
    int r = i;
    // Keep moving either l or r till they meet
    while (l != r) {
        // If we find a pair with sum x, we return true
        if (arr[l] + arr[r] == x)
            return true;
        // If current pair sum is less, move to the higher sum
        if (arr[l] + arr[r] < x)
            l = (l + 1) % n;
        // Move to the lower sum side
        else
            r = (n + r - 1) % n;
    }
    return false;
}
bool findPair(int arr[], int n, int x)
{
    // find pivot element
    int pivot = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            pivot = i + 1;
            break;
        }
    }
    // set left and right pointers
    int left = pivot;
    int right = pivot - 1;
    // loop until left and right pointers meet
    while (left != right) {
        // if sum of elements at left and right pointers is equal to x, return true
        if (arr[left] + arr[right] == x) {
            return true;
        }
        // if sum of elements at left and right pointers is
        // less than x, move left pointer to the next element
        else if (arr[left] + arr[right] < x) {
            left = (left + 1) % n;
        }
        // if sum of elements at left and right pointers is
        // greater than x, move right pointer to the previous element
        else {
            right = (right - 1 + n) % n;
        }
    }
    return false;
}
int main()
{
    int arr[] = { 11, 15, 6, 8, 9, 10 };
    int X = 16;
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << boolalpha << findPair(arr, N, X);
    if (pairInSortedRotated(arr, N, X))
        cout << "\ntrue";
    else
        cout << "\nfalse";
 
    return 0;
}
