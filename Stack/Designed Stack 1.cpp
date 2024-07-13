#include<bits/stdc++.h>
using namespace std;
int mini(int a, int b){
    return a < b ?a: b;
}
struct MinStack{
    stack<pair<int, int> >st;
    void push(int val){
        int Mini = (st.empty())?val :mini(val, st.top().second);
        st.push({val, Mini});
    }
    int pop(){
        int x;
        if(!st.empty()){
            x = st.top().first;
            st.pop();
        }
        else
            cout << "\nstack is empty";
        return x;
    }
    int GetMin(){
        int m = st.top().second;
        return m;
    }
};
int main(){
    MinStack st;
    for(int i = 0; i < 6; i++)
        st.push(i);
    cout << st.GetMin();
}
