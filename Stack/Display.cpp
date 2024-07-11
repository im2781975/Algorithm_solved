#include<iostream>
#include<stack>
using namespace std;
#define Max 1000
class Stack{
    int top;
    public:
    int arr[Max];
    Stack():top(-1){}
    bool push(int x);
    int pop();
    int peek();
    bool IsEmpty();
};
bool Stack::push(int x){
    if(top >= Max -1){
        cout << "Underflow";
        return false;
    }
    else{
        arr[++top] = x;
        //cout << x << " ";
        return true;
    }
}
int Stack::pop(){
    if(top < 0){
        cout << "Underflow";
        return 0;
    }
    int x = arr[top--];
    return x;
}
int Stack::peek(){
    if(top < 0){
        cout << "\nUnderflow";
        return 0;
    }
    else
        return arr[top];
}
bool Stack::IsEmpty(){
    if(top < 0)
        return true;
    return false;
}
int main(){
    Stack st;
    for(int i = 1; i <= 6; i++)
        st.push(i);
    cout << "\nTop Element is: " << st.peek();
    cout << "\nElements are: ";
    while(!st.IsEmpty()){
        cout << st.pop() << " ";
    }
}
