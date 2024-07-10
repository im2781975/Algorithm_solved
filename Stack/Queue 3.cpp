// implement a stack using two queue
#include<iostream>
#include<queue>
using namespace std;
class Queue{
    queue <int> a, b;
    public:
    void push(int x){
        b.push(x);
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }
        queue <int> q = a;
        a = b; b = q;
    }
    void pop(){
        if(a.empty())
            return;
        a.pop();
    }
    int top(){
        if(a.empty())
            return -1;
        return a.front();
    }
    int Getsize(){
        return a.size();
    }
};
int main(){
    Queue q;
    for(int i = 1; i <= 5; i++){
        q.push(i);
        cout << q.top() << " ";
        q.pop();
    }
}

