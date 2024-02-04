#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r);
// This function stops at K'th largest element in arr[l..r] using QuickSort based method.
void KthLargest(int arr[], int l, int r, int K, int N)
{
    // Partition the array around last element and get position of pivot element in sorted array
    int pos = partition(arr, l, r);
    // If position is same as k
    if (pos - l == K - 1)
        return;
    // If position is less, recur for right subarray
    else if (pos - l < K - 1)
        return KthLargest(arr, pos + 1, r, K - pos + l - 1, N);
    // Else recur for left subarray
    else
        return KthLargest(arr, l, pos - 1, K, N);
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int main()
{
    int arr[]
        = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
 
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    // For Largest
    KthLargest(arr, 0, N - 1, k, N);
    // Print KLargest no.
    cout << k << " largest elements are : ";
    for (int i = N - 1; i >= N - k; i--)
        cout << arr[i] << "  ";
    return 0;
}
