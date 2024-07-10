// sort a stack using an auxiliary stack.
#include<iostream>
#include<stack>
using namespace std;
stack <int> SortStack(stack <int> st){
    stack <int> Stack;
    while(!st.empty()){
        int tmp = st.top();
        st.pop();
        while(!Stack.empty() && Stack.top() > tmp){
            st.push(Stack.top());
            Stack.pop();
        }
        Stack.push(tmp);
    }
    return Stack;
}
int main(){
    stack <int> st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(4);
    stack <int>Stack = SortStack(st);
    while(!Stack.empty()){
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
