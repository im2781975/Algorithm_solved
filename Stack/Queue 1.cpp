// implement a stack using Priority queue(min heap)
#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int> pi;
class Stack{
    int cnt;
    priority_queue <pi> pq;
    public:
    Stack():cnt(0){}
    void push(int data);
    void pop();
    int top();
    bool IsEmpty();
};
bool Stack::IsEmpty(){
    return pq.empty();
}
void Stack::push(int data){
    cnt++;
    pq.push(pi(cnt, data));
}
void Stack::pop(){
    if(IsEmpty()){
        cout << "\nQueue is empty";
        abort();
    }
    cnt--;
    pq.pop();
}
int Stack::top(){
    pi item = pq.top();
    return item.second;
}
int main(){
    Stack *st = new Stack();
    for(int i = 1; i < 20; i+= 3){
        st->push(i);
        cout << st->top()<< " ";
        st->pop();
    }
}
