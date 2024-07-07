// implement Queue using two stacks with costly deQueue()
#include<bits/stdc++.h>
using namespace std;
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
int main(){
    Queue q;
    cout << q.deque() << "\n";
    for(int i = 1; i <= 5; i++){
        q.enque(i);
        cout << q.deque() << " ";
    }
}
