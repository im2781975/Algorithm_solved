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
//****//
class node{
    public:
    int data;
    node *nxt;
};
void Reverse(node **head){
    stack <node*> st;
    node *tmp = *head;
    while(tmp ->nxt!=NULL){
        st.push(tmp);
        tmp = tmp->nxt;
    }
    *head = tmp;
    while(!st.empty()){
        tmp-> nxt = st.top();
        st.pop();
        tmp = tmp ->nxt;
    }
    tmp->nxt = NULL;
}
void print(node *tmp){
    while(tmp !=NULL){
        cout << tmp ->data << " ";
        tmp = tmp->nxt;
    }
    cout << "\n";
}
void InsertBack(node **head, int val){
    node *newnode = new node();
    newnode ->data = val;
    newnode ->nxt = NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    else{
        node *tmp = *head;
        while(tmp->nxt!=NULL)
            tmp = tmp->nxt;
        tmp->nxt = newnode;
        return;
    }
};
int main(){
    Stack *st = new Stack();
    for(int i = 0; i < 5; i++)
        st->push(i);
    st->Display();
    st->Reverse();
    st->Display();
    //****//
    node *head = NULL;
    InsertBack(&head, 1);
    InsertBack(&head, 2);
    InsertBack(&head, 3);
    InsertBack(&head, 4);
    InsertBack(&head, 5);
    print(head);
    Reverse(&head);
    print(head);
}
