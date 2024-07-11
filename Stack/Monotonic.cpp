#include<iostream>
#include<stack>
using namespace std;
// Function to build Monotonic increasing stack
void Increasing(int *arr, int n){
    stack <int> st;
    for(int i = 0; i < n; i++){
        while(st.size() > 0 && st.top() > arr[i])
            st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int ans[sz], j = sz - 1;
    while(!st.empty()){
        ans[j] = st.top();
        st.pop(); j--;
    }
    cout << "\nArray is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nStack is: ";
    for(int i = 0; i < sz; i++)
        cout << ans[i] << " ";
}
void Decreasing(int *arr, int n){
    stack <int> st;
    for(int i = 0; i < n; i++){
        while(st.size() > 0 && st.top() < arr[i])
            st.pop();
        st.push(arr[i]);
    }
    int sz = st.size();
    int ans[sz], j = sz - 1;
    while(!st.empty()){
        ans[j] = st.top();
        st.pop(); j--;
    }
    cout << "\nArray is: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nStack is: ";
    for(int i = 0; i < sz; i++)
        cout << ans[i] << " ";
}
int main(){
    int arr[]{1, 4, 5, 3, 12, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Increasing(arr, n);
    Decreasing(arr, n);
}
