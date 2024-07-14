#include<iostream>
#include<queue>
using namespace std;
class Queue{
    queue <int> q;
    public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool IsEmpty();
};
void Queue::push(int x){
    q.push(x);
    for(int i = 0; i < q.size(); i++){
        q.push(q.front());
        q.pop();
    }
}
void Queue::pop(){
    if(q.empty()){
        cout << "Empty";
        abort();
    }
    q.pop();
}
int Queue::top(){
    if(q.empty())
        throw"Empty";
    return q.front();
    return (q.empty() ? -1: q.front());
}
int Queue::size(){
    return q.size();
}
bool Queue::IsEmpty(){
    return (q.empty());
}
// implement a stack using one queue and recursion
class Queue{
    queue <int> q;
    public:
    void push(int data, int size);
    void pop();
    int top();
    int GetSize();
    bool IsEmpty();
};
void Queue::push(int data, int size){
    // Push the cur element first & After every recursion add the front element again
    q.push(data);
    if(size <= 0)
        return;
    int x = q.front();
    q.pop();
    size--;
    Queue::push(x, size);
}
void Queue::pop(){
    if(IsEmpty()){
        cout << "\nQueue is Empth";
        abort();
    }
    q.pop();
}
int Queue::top(){
    return ((IsEmpty())? -1 : q.front());
}
int Queue::GetSize(){
    return q.size();
}
bool Queue::IsEmpty(){
    return q.empty();
}
int main(){
    Queue q;
    cout << "Elements are: ";
    for(int i = 1; i <= 5; i++){
        q.push(i);
        cout << q.top() << " ";
        q.pop();
    }
    cout << "\nSize is: " << q.size();
    cout << "\nIsEmpty: " << q.IsEmpty();
    //****//
    Queue q;
    for(int i = 1; i <= 6; i++){
        q.push(i, q.GetSize());
        cout << q.top() << " ";
        q.pop();
    }
}
