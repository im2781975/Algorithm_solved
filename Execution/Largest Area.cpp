// find maximum rectangular area in linear time 
#include <bits/stdc++.h> 
using namespace std; 
// find the maximum rectangular  area under given histogram with n bars 
int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes of hist[] array. The bars stored in stack are 
    // always in increasing order of their heights. 
    stack<int> s;
    int max_area = 0;
    // Initialize max area 
    int tp; 
    // To store top of stack 
    int area_with_top; 
    // To store area with top bar  as the smallest bar 
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) { 
        // If this bar is higher than the bar on top  stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack, then calculate area of rectangle with stack 
        // top as the smallest (or minimum height) bar.  'i' is 'right index' for the top and element
        // before top in stack is 'left index' 
        else { 
            tp = s.top();
            // store the top index 
            s.pop(); 
            // pop the top 
  
            // Calculate the area with hist[tp] stack 
            // as smallest bar 
            area_with_top 
                = hist[tp] 
                  * (s.empty() ? i : i - s.top() - 1); 
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    }
    // Now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar 
    while (s.empty() == false) { 
        tp = s.top(); 
        s.pop(); 
        area_with_top 
            = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    }
    return max_area; 
}
int getMaxArea(int arr[], int n) 
{
    stack<int> s; 
    // we push -1 to the stack because for some elements  there will be no previous smaller element in the 
    // array and we can store -1 as the index for previous  smaller. 
    s.push(-1); 
    int area = arr[0]; 
    int i = 0; 
    // We declare left_smaller and right_smaller array of  size n and initialize them with -1 and n as their default value. 
    //left_smaller[i] will store the index of previous smaller element for ith element of the 
    // array. right_smaller[i] will store the index of next smaller element for ith element of the array. 
    vector<int> left_smaller(n, -1), right_smaller(n, n); 
    while (i < n) { 
        while (!s.empty() && s.top() != -1 
               && arr[s.top()] > arr[i]) { 
            // if the current element is smaller than element with index stored on the top of stack 
            // then, we pop the top element and store the current element index as the right_smaller  for the popped element. 
            right_smaller[s.top()] = i; 
            s.pop(); 
        } 
        if (i > 0 && arr[i] == arr[i - 1]) { 
            // we use this condition to avoid the unnecessary loop to find the left_smaller. 
            // since the previous element is same as current element, the left_smaller will always be the  same for both. 
            left_smaller[i] = left_smaller[i - 1]; 
        } 
        else { 
            // Element with the index stored on the top of the stack is always smaller than
            //the current element. Therefore the left_smaller[i] will  always be s.top(). 
            left_smaller[i] = s.top(); 
        } 
        s.push(i); 
        i++; 
    } 
    for (int j = 0; j < n; j++) { 
        // here we find area with every element as the  smallest element in their range and compare it 
        // with the previous area.  in this way we get our max Area form this
        area = max(area, arr[j] 
                             * (right_smaller[j] - left_smaller[j] - 1)); 
    } 
    return area; 
} 
int main() 
{ 
    int hist[] = { 6, 2, 5, 4, 5, 1, 6 }; 
    int n = sizeof(hist) / sizeof(hist[0]); 
    cout << "Maximum area is " << getMaxArea(hist, n); 
    return 0; 
}
