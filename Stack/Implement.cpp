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
        node *tmp = top;
        top = top->nxt;
        return tmp;
    }
    void Display(){
        node *tmp = top;
        cout << "\nElements are: ";
        while(tmp !=NULL){
            cout << tmp->data << " ";
            tmp = tmp->nxt;
        }
    }
    //Reverse() function is to reverse the linked list, not to 
    //interact with the console.For this it doesn't have cout statements within it. 
    void Reverse(){
        node *cur, *prv, *succ;
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
    for(int i = 1; i <= 6; i++){
        st->push(i);
    }
    st->Display();
    st->Reverse();
    st->Display();
}

