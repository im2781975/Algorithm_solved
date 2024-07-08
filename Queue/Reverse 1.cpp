#include<bits/stdc++.h>
using namespace std;
// reverse first k elements of a queue.
void ReverseFirst(int k, queue <int> &q){
    if(q.empty() || k > q.size())
        return;
    if(k <= 0)
        return;
    stack <int> st;
    for(int i = 0; i < k; i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i = 0; i < q.size() - k; i++){
        q.push(q.front());
        q.pop();
    }
}
void print(queue <int> &q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
int main(){
    queue <int> q;
    for(int i = 10; i <= 100; i+=10)
        q.push(i);
    int k = 5;
    ReverseFirst(k, q);
    print(q);
}
