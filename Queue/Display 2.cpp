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
// implement Queue using two stacks with costly deQueue()
struct Queue{
    stack <int> a, b;
    void enque(int x){
        a.push(x);
    }
    int deque(){
        if(a.empty() && b.empty())
            return -1;
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        int x = b.top();
        b.pop();
        return x;
    }
};
// 
void print(queue <int> q)
{
    queue <int> tmp = q;
    while(!tmp.empty()){
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << "\n";
}
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    ///
    Queue q;
    cout << q.deque() << "\n";
    for(int i = 1; i <= 5; i++){
        q.enque(i);
        cout << q.deque() << " ";
    }
    ////
    queue <int> a, b;
    for(int i =0; i < 10; i+= 2)
        a.push(i);
    cout << "Befor Swap: \n";
    print(a);
    for(int i = 10; i < 20; i+= 2)
        b.push(i);
    print(b);
    cout << "\nAfter Swap: \n";
    a.swap(b);
    print(a);
    print(b);
    cout << "Is empty: " << a.empty();
}
