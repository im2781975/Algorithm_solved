#include<iostream>
#include<stack>
using namespace std;
class Stack{
    int front, rear, cap, size, *arr;
    public:
    Stack(int cap){
        this->cap = cap;
        arr = new int[cap];
        front = size = 0;
        rear = cap -1;
    }
    bool IsFull(){
        return (size == cap);
    }
    bool IsEmpty(){
        return (size == 0);
    }
    void push(int x){
        if(IsFull())
            return;
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }
    void pop(){
        if(IsEmpty())
            return;
        front = (front + 1) %cap;
        size--;
    }
    int top(){
        if(IsEmpty())
            return -1;
        return arr[front];
    }
    int GetSize(){
        return size;
    }
};
int main(){
    Stack st(5);
    for(int i = 1; i <= 6; i++){
        st.push(i);
        cout << st.top() << " ";
        st.pop();
    }
    cout <<"\nSize is: " << st.GetSize();
}
