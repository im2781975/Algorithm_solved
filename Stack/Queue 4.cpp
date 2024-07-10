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
}
