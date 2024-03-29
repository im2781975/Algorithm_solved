// find the pair with sum closest   to a given no using above approach. 
#include <bits/stdc++.h> 
using namespace std; 
// Function to prints the pair with sum closest to x 
void closestPair(int arr[], int n, int x) { 
    // Initialize variables pointing to the first and last elements of the array 
    int l = 0, r = n - 1; 
    // To store indexes of result pair 
    int res_l, res_r; 
    // variable to store current minimum difference 
    int minDiff = INT_MAX; 
    // Iterate over the array using 
    for (int i = 0; i < n; i++) { 
        int e = arr[i]; 
          
        // Use binary search to find the element  'elem' in the array such that 'e+elem' is closest to 'x'. 
        int left = i + 1, right = n - 1; 
        while (left <= right) { 
            int mid = (left + right) / 2; 
  
            if (arr[mid] + e == x) { 
                res_l = i; 
                res_r = mid; 
                minDiff = 0; 
                break; 
            } 
            // Check if this pair is closer than the closest pair so far 
            if (abs(arr[mid] + e - x) < minDiff) { 
                minDiff = abs(arr[mid] + e - x); 
                res_l = i; 
                res_r = mid; 
            } 
            if (arr[mid] + e < x)
                left = mid + 1; 
            else 
                right = mid - 1; 
        } 
    } 
    // Print the pair 
    cout << "The closest pair is " << arr[res_l] << " and " << arr[res_r]; 
}
int main() { 
    int arr[] = {10, 22, 28, 29, 30, 40}; 
    int x = 54; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    closestPair(arr, n, x); 
    return 0; 
} 
