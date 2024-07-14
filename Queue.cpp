#include<iostream>
#include<stack>
using namespace std;
// Queue using two stacks with costly enQueue()
struct Queue{
    stack <int> a, b;
    void enqueue(int x){
        // Move all elements from  a to b
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        // Push everything back to a
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
    }
    int dequeue(){
        if(a.empty())
            return -1;
        int x = a.top();
        a.pop();
        return x;
    }
};
// implement a stack using dequeue
class Deque{
    deque <int>dq;
    public:
    void push(int data){
        
        dq.push_back(data);
    }
    int pop(){
        int item = dq.back();
        dq.pop_back();
        return item;
    }
    int GetSize(){
        return dq.size();
    }
    bool IsEmpty(){
        return dq.empty();
    }
    int top(){
        if(IsEmpty())
            return -1;
        return dq.back();
    }
};
int main(){
    Queue q;
    for(int i = 0; i <= 10; i+= 2){
        q.enqueue(i);
        cout << q.dequeue() << " ";
    }
    //****//
    Deque dq;
    for(int i = 1; i < 10; i+= 2)
        dq.push(i);
    cout << "\nSize is: " << dq.GetSize();
    cout << "\nElements are: ";
    while(!dq.IsEmpty()){
        cout << dq.top() << " ";
        dq.pop();
    }
    cout << "\nSize is: " << dq.GetSize();
}
