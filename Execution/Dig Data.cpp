#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
// A recursive binary search based function. It returns index of x in given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at one of the middle 3 positions
        if (arr[mid] == x)
            return mid;
        if (mid > l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid < r && arr[mid + 1] == x)
            return (mid + 1);
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 2, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 2, r, x);
    }
    // We reach here when element is not present in array
    return -1;
}
// function takes an infinite size array and a key to be searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be infinite in this function.
int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];
    // Find h to do binary search
    while (val < key)
    {
        l = h;        
        // store previous high
        h = 2*h;      
        // double high index
        val = arr[h]; 
        // update new val
    }
    // at this point we have updated low and high indices, Thus use binary search between them
    return binarySearch(arr, l, h, key);
}
int main(void)
{
    int arr[] = { 3, 2, 10, 4, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = linearSearch(arr, n, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    int ans = findPos(arr, 10);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}
