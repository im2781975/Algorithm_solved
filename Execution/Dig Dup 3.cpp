//Including necessary header files
#include <bits/stdc++.h>
using namespace std;
// Function to find the index of first repeating element in an array
int firstRepeatingElement(int arr[], int n)
{
    // Nested loop to check for repeating elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If a repeating element is found, return its index
            if (arr[i] == arr[j]) {
                return i;
            }
        }
    }
    // If no repeating element is found, return -1
    return -1;
}
// prints the first repeating element in arr[]
void printFirstRepeating(int arr[], int n)
{
    // Initialize index of first repeating element
    int min = -1;
    // Creates an empty hashset
    set<int> myset;
    // Traverse the input array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If element is already in hash set, update min
        if (myset.find(arr[i]) != myset.end())
            min = i;
 
        else // Else add element to hash set
            myset.insert(arr[i]);
    }
    if (min != -1)
        cout << "The first repeating element is "
             << arr[min];
    else
        cout << "There are no repeating elements";
}
// prints the first repeating element in arr[]
void printFirstRepeating(int arr[], int n)
{
    // This will set k=1, if any repeating element found
    int k = 0;
    // max = maximum from (all elements & n)
    int max = n;
    for (int i = 0; i < n; i++)
        if (max < arr[i])
            max = arr[i];
    // Array a is for storing 1st time occurrence of element initialized by 0
    int a[max + 1] = {};
    // Store 1 in array b,if element is duplicate initialized by 0
    int b[max + 1] = {};
    for (int i = 0; i < n; i++) {
        // Duplicate element found
        if (a[arr[i]]) {
            b[arr[i]] = 1;
            k = 1;
            continue;
        }
        else
            // storing 1st occurrence of arr[i]
            a[arr[i]] = i + 1;
    }
    if (k == 0)
        cout << "No repeating element found" << endl;
    else {
        int min = max + 1;
        // trace array a & find repeating element with min index
        for (int i = 0; i < max + 1; i++)
            if (a[i] && min > a[i] && b[i])
                min = a[i];
        cout << arr[min - 1];
    }
    cout << endl;
}
// function prints the first repeating element in arr[]
void firstRepeating(int arr[], int n) {
     
        int max = -1;
          //Finding max
        for(int i = 0 ; i<n;i++){
           if(max<arr[i]){
               max = arr[i];
           }
        }
        //Creating array
        int hash[max+1]={0};
        //Mapping/counting 
        for(int i =0;i<n; i++){
            hash[arr[i]]++;
        }
        //Variable for storing ans
          int repeating=INT_MIN;
        //Checking repeatibng element
        for(int i =0;i<n; i++){
            if(hash[arr[i]]>1){
                repeating=arr[i];
                  break;
            }
        }
          if(repeating==INT_MIN){
          cout << "There are no repeating elements";
        }
          else{
          cout << "The first repeating element is : "
             <<repeating;
        }
    }
int main()
{
    int arr[] = { 10, 5, 3, 4, 3, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // Finding the index of first repeating element
    printFirstRepeating(arr, n);
    int index = firstRepeatingElement(arr, n);
    // Checking if any repeating element is found or not
    if (index == -1) {
        cout << "No repeating element found!" << endl;
    }
    else {
        // Printing the first repeating element and its index
        cout << "First repeating element is " << arr[index]
             << endl;
    }
    return 0;
}
