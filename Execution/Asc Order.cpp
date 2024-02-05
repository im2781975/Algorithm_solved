// find the element which is greater than all left elements and smaller than all right elements.
#include <bits/stdc++.h>
using namespace std;
bool check(int arr[], int n,int ind){
    int i=ind-1;
    int j=ind+1;
     
    while(i>=0){
        if(arr[i]>arr[ind])
        {return false;}
        i--;
    }
    while(j<n){
        if(arr[j]<arr[ind]){return false;}
        j++;
    }
    return true;
}
// Function to return the index of the element which is greater than all left elements and smaller than all right elements
int findElement(int arr[], int n)
{
    // Traverse array from 1st to n-1 th index because Extrem elements can't be aur answer
    for (int i=1; i<n-1; i++)
    {
        if(check(arr,n,i)){return i;}
    }
    return -1;
}
// Function to return the index of the element which is greater than
// all left elements and smaller than all right elements.
int findElement(int arr[], int n)
{
    // leftMax[i] stores maximum of arr[0..i-1]
    int leftMax[n];
    leftMax[0] = INT_MIN;
    // Fill leftMax[1..n-1]
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
 
    // Initialize minimum from right
    int rightMin = INT_MAX;
    // Traverse array from right
    for (int i=n-1; i>=0; i--)
    {
        // Check if we found a required element
        if (leftMax[i] < arr[i] && rightMin > arr[i])
             return i;
        // Update right minimum
        rightMin = min(rightMin, arr[i]);
    }
    return -1;
}
int findElement(int a[], int n)
{
    // Base case
    if (n == 1 || n == 2) {
        return -1;
    }
    // 1.element is the possible candidate for the solution of the problem. 
    // 2.idx is the index of the possible candidate. 
    // 3.maxx is the value which is maximum on the left side of the array. 
    // 4.bit tell whether the loop is terminated from the if condition or from the else condition when loop do not satisfied the condition.
    // 5.check is the variable which tell whether the element is updated or not
    int element = a[0], maxx = a[0], bit = -1, check = 0;
    int idx = -1;
    // The extreme two of the array can not be the solution Therefore iterate the loop from i = 1 to < n-1
    for (int i = 1; i < (n - 1);){
        // here we find the possible candidate where Element
        // with left side smaller and right side greater.
        // when the if condition fail we check and update in else condition.
        if (a[i] < maxx && i < (n - 1)) {
            i++;
            bit = 0;
        }
        // here we update the possible element if the
        // element is greater than the maxx (maximum element
        // so far). In while loop we sur-pass the value which is greater than the element
        else {
            if (a[i] >= maxx) {
                element = a[i];
                idx = i;
                check = 1;
                maxx = a[i];
            }
            if (check == 1) {
                i++;
            }
            bit = 1;
            while (a[i] >= element && i < (n - 1)) {
                if (a[i] > maxx) {
                    maxx = a[i];
                }
                i++;
            }
            check = 0;
        }
    }
    // checking for the last value and whether the loop is terminated from else or if block.
    if (element <= a[n - 1] && bit == 1) {
        return idx;
    }
    else
        return -1;
}
int main()
{
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    int n = sizeof arr / sizeof arr[0];
    cout << "Index of the element is " << findElement(arr, n);
    return 0;
}
