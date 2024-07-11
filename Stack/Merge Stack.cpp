#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
};
class Stack{
    public:
    node *head, *tail;
    Stack():head(NULL), tail(NULL){}
};
Stack *create(){
    Stack *st = new Stack();
    return st;
}
void push(int data, Stack *st){
    node *newnode = new node();
    newnode ->data = data;
    newnode ->nxt = st->head;
    if(st->head == NULL)
        st->tail = newnode;
    st->head = newnode;
}
int pop(Stack *st){
    if(st->head == NULL){
        cout << "\nStack is Empty";
        return 0;
    }
    node *tmp = st->head;
    st->head = st->head->nxt;
    int value = tmp->data;
    delete tmp; return value;
}
void merged(Stack *a, Stack *b){
    if(a->head == NULL){
        a->head = b->head;
        a->tail = b->tail;
    }
    else{
        a->tail->nxt= b->head;
        //After linking, the function updates a's tail to 
        //point to b's tail, as b's elements are now at the bottom of a.
        a->tail = b->tail;
    }
}
void Display(Stack *st){
    node *trv = st->head;
    cout <<"\nElements are: ";
    while(trv !=NULL){
        cout << trv->data << " ";
        trv = trv->nxt;
    }
}
int main(){
    Stack *a = create();
    Stack *b = create();
    for(int i = 1; i <= 5; i++){
        push(i, a);
        push(i+5, b);
    }
    Display(a);
    Display(b);
    merged(b, a);
    Display(a);
}
