#include <bits/stdc++.h>
using namespace std;
// Recursive solution for finding bitonic point
int findMaximum(int arr[], int low, int high)
{
      // if there is only one element
    if (low == high)
        return arr[high];
      // finding the mid index
    int mid = low + (high - low) / 2;
      // if the value of mid index is greater than left and right value
    if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
        return arr[mid];
      // if value on mid index is greater than next index shift the search space to right half
    else if (arr[mid] < arr[mid + 1])
        return findMaximum(arr, mid + 1, high);
      // else vice-versa i.e. to left half
    else
        return findMaximum(arr, low, mid - 1);
}
int maxInBitonic(int arr[], int low, int high)
{
    // find out the size of the array for edge case checking
    int n = high + 1;
    // main code goes as follows
    while (low <= high) {
        // find out the mid
        int mid = low + (high - low) / 2;
          // if mid index value is maximum 
        if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1])
              return arr[mid];
        // reducing search space by moving to right
        else if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        // reducing search space by moving to left
        else
            high = mid - 1;
    }
    return arr[high];
}
int findMax(int arr[], int n)
{
    stack<int> s;
    int max = 0;
    // traverse the array from left to right
    for (int i = 0; i < n; i++) {
        // push the index onto the stack if the element is less than or equal to the previous element
        if (s.empty() || arr[i] <= arr[s.top()]) {
            s.push(i);
        }
        else {
            // pop all the indices from the stack until we find an index whose corresponding element is greater than the current element
            while (!s.empty() && arr[i] > arr[s.top()]) {
                int index = s.top();
                s.pop();
                // update the maximum element
                if (arr[index] > max) {
                    max = arr[index];
                }
            }
            // push the current index onto the stack
            s.push(i);
        }
    }
    // the maximum element is the element corresponding to the last index remaining on the stack
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        if (arr[index] > max) {
            max = arr[index];
        }
    }
    return max;
}
int main()
{
    int arr[] = { 1, 3, 50, 10, 9, 7, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum element is "
         << findMaximum(arr, 0, n - 1);
    cout << "The maximum element is "<< maxInBitonic(arr, 0, n - 1);
    cout << "The maximum element is "
         << findMax(arr, n);
    return 0;
}
