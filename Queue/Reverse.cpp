#include<bits/stdc++.h>
using namespace std;
void print(queue <int> &q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
void reverse(queue <int> &q){
    if(q.size() == 0)
        return;
    int first = q.front();
    q.pop();
    reverse(q);
    q.push(first);
}
void Reverse(queue <int> &q){
    stack <int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
};
int main(){
    queue <int> q;
    for(int i = 0; i <= 100; i+=10)
        q.push(i);
    reverse(q);
    Reverse(q);
    print(q);
}
