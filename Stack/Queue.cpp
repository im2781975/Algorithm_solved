// Queue using two stacks with costly enQueue()
#include<iostream>
#include<stack>
using namespace std;
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
int main(){
    Queue q;
    for(int i = 0; i <= 10; i+= 2){
        q.enqueue(i);
        cout << q.dequeue() << " ";
    }
}
