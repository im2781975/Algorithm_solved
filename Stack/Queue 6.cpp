#include<iostream>
#include<deque>
using namespace std;
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
