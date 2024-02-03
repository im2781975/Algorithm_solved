#include <bits/stdc++.h>
using namespace std;
//Function to get index of ceiling of x in arr[]
int ceilSearch(int arr[], int low, int high, int x) 
{ 
    int i; 
     
    // If x is smaller than or equal to first element,   then return the first element 
    if(x <= arr[low]) 
        return low; 
    // Otherwise, linearly search for ceil value 
    for(i = low; i < high; i++) 
    { 
        if(arr[i] == x) 
        return i; 
        // if x lies between arr[i] and arr[i+1] including arr[i+1], then return arr[i+1] 
        if(arr[i] < x && arr[i+1] >= x) 
        return i+1; 
    }     
    // if we reach here then x is greater than the last element of the array, return -1 in this case
    return -1; 
}
int ceilSearch(int arr[], int low, int high, int x)
{
    int mid;
 
    // If x is smaller than or equal to the first element, then return the first element
    if (x <= arr[low])
        return low;
    // If x is greater than the last element,then return -1
    if (x > arr[high])
        return -1;
    //get the index of middle element of arr[]
    mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
 
    // If x is greater than arr[mid],then either arr[mid + 1] is ceiling of x or ceiling lies in arr[mid+1...high]
    else if (arr[mid] < x) {
        if (mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, x);
    }
    //If x is smaller than arr[mid],then either arr[mid] is ceiling of x or ceiling lies in arr[low...mid-1]
    else {
        if (mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }
}
int ceilSearch(int arr[], int low, int high, int x)
{
    // base condition if length of arr == 0 then return -1
    if (sizeof(arr) / sizeof(arr[0]) == 0) {
        return -1;
    }
    int mid;
    // this while loop function will run until condition not break once condition break loop will return start and
    // ans is low which will be next smallest greater than target which is ceiling
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main() 
{ 
    int arr[] = {1, 2, 8, 10, 10, 12, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 3; 
    int index = ceilSearch(arr, 0, n-1, x); 
    if(index == -1) 
        cout << "Ceiling of " << x << " doesn't exist in array "; 
    else
        cout << "ceiling of " << x << " is " << arr[index]; 
     
    return 0; 
} 
