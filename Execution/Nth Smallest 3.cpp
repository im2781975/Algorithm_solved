#include <iostream>
using namespace std;
// This function returns the kth smallest element in an array
int kthSmallest(int arr[], int n, int k) {
    // First, find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    // Create an array to store the frequency of each  element in the input array
    int freq[max_element + 1] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    // Keep track of the cumulative frequency of elements in the input array
    int count = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] != 0) {
            count += freq[i];
            if (count >= k) {
                // If we have seen k or more elements, return the current element
                return i;
            }
        }
    }
    return -1;
}
// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
    // Sort the given array
    sort(arr, arr + N);
    // Return k'th element in the sorted array
    return arr[K - 1];
}
int partition(int arr[], int l, int r);
// This function returns K'th smallest element in arr[l..r] using QuickSort based method. 
int kthSmallest(int arr[], int l, int r, int K)
{
    // If k is smaller than number of elements in array
    if (K > 0 && K <= r - l + 1) {
        // Partition the array around last element and get position of pivot element in sorted array
        int pos = partition(arr, l, r);
        // If position is same as k
        if (pos - l == K - 1)
            return arr[pos];
        if (pos - l > K - 1) 
        // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos - 1, K);
        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r, K - pos + l - 1);
    }
    // If k is more than number of elements in array
    return INT_MAX;
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Standard partition process of QuickSort(). It considers the last element as pivot and 
//moves all smaller element to left of it and greater elements to right
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
int main() {
    int arr[] = {12,3,5,7,19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << "The " << k << "th smallest element is " << kthSmallest(arr, n, k) << endl;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n - 1, K);
    return 0;
}
