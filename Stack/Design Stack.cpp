#include<iostream>
#include<stack>
using namespace std;
// A user defined stack that supports getMin() in addition to push() and pop()
struct Stack{
    stack <int> st;
    int mini;
    void push(int x){
        if(st.empty()){
            mini = x;
            st.push(x);
            return;
        }
        else if(x < mini){
            st.push(2 * x - mini);
            mini = x;
        }
        else
            st.push(x);
        cout << "\nInserted Element is: " << x;
    }
    void pop(){
        if(st.empty()){
            cout << "Stack is empty";
            return;
        }
        int Top = st.top();
        st.pop();
        if(Top < mini){
            cout << mini << " ";
            mini = 2 * mini - Top;
        }
        else
            cout << Top;
    }
    void peek(){
        if(st.empty()){
            cout << "Stack Is empty";
            abort();
        }
        int Top = st.top();
        (Top < mini)?cout << "\nPeek: " << Top:cout << "\nPeek: " << mini;
    }
    void GetMin(){
        if(st.empty()){
            cout << "stack is empty";
            abort();
        }
        cout << "\nMin: " << mini;
    }
};
int main(){
    Stack st;
    for(int i = 1; i <= 5; i++)
        st.push(i);
    st.GetMin();
    st.peek();
}
