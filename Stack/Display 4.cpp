// Implement a stack using singly linked list
#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data; node *nxt;
    node(int val):data(val), nxt(NULL){}
};
class Stack{
    node *top;
    public:
    Stack():top(NULL){}
    void push(int x){
        node *newnode = new node(x);
        if(newnode == NULL){
            cout << "Stack overflow";
            exit(1);
        }
        newnode->data = x;
        newnode->nxt = top;
        top = newnode;
    }
    bool IsEmpty(){
        return top == NULL;
    }
    int peek(){
        if(!IsEmpty())
            return top->data;
        exit(1);
    }
    void pop(){
        node *tmp = top;
        if(top == NULL){
            cout << "\nUnderflow";
            exit(1);
        }
        top = top->nxt;
        delete tmp;
    }
    void Display(){
        node *tmp = top;
        if(top == NULL){
            cout << "\nUnderflow";
            exit(1);
        }
        cout << "\nElements are: ";
        while(tmp!=NULL){
            cout << tmp->data << " ";
            tmp = tmp->nxt;
        }
    }
};
int main(){
    Stack st;
    for(int i = 1; i <= 10; i++)
        st.push(i);
    st.Display();
    cout << "\nElements are: ";
    while(!st.IsEmpty()){
        cout << st.peek() << " ";
        st.pop();
    }
}
