// implement Queue using one stack and recursive call stack.convert stack to queue
#include<bits/stdc++.h>
using namespace std;
struct Queue{
    stack <int> st;
    void enqueue(int x){
        st.push(x);
    }
    int dequeue(){
        if(st.empty())
            return -1;
        int x = st.top();
        st.pop();
        if(st.empty())
            return x;
        // recursive call
        int item = dequeue();
        // push popped item back to the stack
        st.push(x);
        // return the result of deQueue() call
        return item;
    }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
}
