#include<bits/stdc++.h>
using namespace std;
// find if there exists a pair of elements in the array whose difference is n
void findPair(int arr[], int n, int diff) {
    // Nested loop to compare all possible pairs of elements
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j)
                continue;
            // If the difference between the two elements is n, print them
            if((arr[j] - arr[i]) == diff) {
                cout << "Pair Found: (" << arr[i] << ", " << arr[j] << ")";
                  return;
            }
        }
    }
    cout << "No such pair";
}
// The function assumes that the array is sorted 
bool findPair(int arr[], int size, int n) 
{ 
    // Initialize positions of two elements 
    int i = 0; 
    int j = 1; 
    // Search for a pair 
    while (i < size && j < size) 
    { 
        if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
        { 
            cout << "Pair Found: (" << arr[i] <<
                        ", " << arr[j] << ")"; 
            return true; 
        } 
        else if (arr[j]-arr[i] < n) 
            j++; 
        else
            i++; 
    }
    cout << "No such pair"; 
    return false; 
} 
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    // Initialize positions of two elements
    int l = 0;
    int r = 1;
    // take absolute value of difference this does not affect the pair as A-B=diff is same as B-A= -diff
    n = abs(n);
    // Search for a pair.These loop running conditions are sufficient
    while (l <= r and r < size) {
        int diff = arr[r] - arr[l];
        if (diff == n
            and l != r) 
            // we need distinct elements in pair. so l!=r
        {
            cout << "Pair Found: (" << arr[l] << ", "
                 << arr[r] << ")";
            return true;
        }
        else if (diff > n) 
        // try to reduce the diff
            l++;
        else
        // Note if l==r then r will be advanced thus no pair will be missed
            r++;
    }
    cout << "No such pair";
    return false;
}
// function assumes that the array is sorted
bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
        // Check if any element whose frequency is greater than 1 exist or not for n == 0
        if (n == 0 && mpp[arr[i]] > 1)
            return true;
    }
    // Check if difference is zero & we are unable to find any duplicate or
    // element whose frequency is greater than 1 then no such pair found.
    if (n == 0)
        return false;
 
    for (int i = 0; i < size; i++) {
        if (mpp.find(n + arr[i]) != mpp.end()) {
            cout << "Pair Found: (" << arr[i] << ", "
                 << n + arr[i] << ")";
            return true;
        }
    }
    cout << "No Pair found";
    return false;
}
int main() {
    int arr[] = { 1, 8, 30, 40, 100 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = -60;
    findPair(arr, n, diff);
    findPair(arr, n, diff);
    findPair(arr, n, diff);
    return 0;
}
