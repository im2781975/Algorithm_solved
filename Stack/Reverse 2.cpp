// implement Stack using linked list so that reverse 
#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
    node(int val):data(val), nxt(NULL){}
};
class Stack{
    public:
    node *top;
    void push(int data){
        node *newnode = new node(data);
        if(top == NULL){
            top = newnode;
            return;
        }
        else{
            newnode->nxt = top;
            top = newnode;
        }
    }
    node *pop(){
        node *newnode = top;
        top = top->nxt;
        return newnode;
    }
    void Display(){
        node *newnode = top;
        while(newnode !=NULL){
            cout << newnode->data << " ";
            newnode = newnode ->nxt;
        }
        cout << "\n";
    }
    void Reverse(){
        node *cur ,*prv, *succ;
        cur = prv = top;
        cur = cur->nxt;
        prv->nxt = NULL;
        while(cur !=NULL){
            succ = cur->nxt;
            cur->nxt = prv;
            prv = cur;
            cur = succ;
        }
        top = prv;
    }
};
int main(){
    Stack *st = new Stack();
    for(int i = 0; i < 5; i++)
        st->push(i);
    st->Display();
    st->Reverse();
    st->Display();
}
