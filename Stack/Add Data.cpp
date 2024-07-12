//add two numbers represented by Linked Lists using Stack
#include<iostream>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
};
node *create(int val){
    node *newnode = new node();
    newnode->nxt = NULL;
    newnode-> data = val;
    return newnode;
}
// function that returns the sum of two numbers represented by linked lists
node *AddTwoNum(node *l1, node *l2){
    node *prv = NULL;
    stack <node*>a, b, c;
    //Fill First & second second with list elements
    while(l1 !=NULL){
        a.push(l1);
        l1 = l1->nxt;
    }
    while(l2!=NULL){
        b.push(l2);
        l2 = l2->nxt;
    }
    int carry = 0;
    while(!a.empty() &&! b.empty()){
        int sum = a.top()->data + b.top()->data + carry;
        node *tmp = create(sum % 10);
        c.push(tmp);
        if(sum > 9)
            carry = 1;
        else
            carry = 0;
        a.pop(); b.pop();
    }
    while(!a.empty()){
        int sum = a.top()->data + carry;
        node *tmp =create(sum % 10);
        c.push(tmp);
        if(sum > 9)
            carry = 1;
        else
            carry = 0;
        a.pop();
    }
    while(!b.empty()){
        int sum = b.top()->data + carry;
        node *tmp = create(sum % 10);
        c.push(tmp);
        if(sum > 9)
            carry = 1;
        else
            carry = 0;
        b.pop();
    }
    // If carry is still present create a new node with 
    //value 1 and push it to the third stack
    if(carry == 1){
        node *tmp = create(1);
        c.push(tmp);
    }
    // Link all the elements inside third stack with each other
    if(!c.empty())
        prv = c.top();
    while(!c.empty()){
        node *tmp = c.top();
        c.pop();
        if(c.size() == 0)
            tmp->nxt = NULL;
        else
            tmp->nxt = c.top();
    }
    return prv;
}
void Display(node *head){
    cout << "\nElements are: ";
    if(head == NULL)
        return;
    while(head->nxt !=NULL){
        cout << head->data << " ";
        head = head ->nxt;
    }
    cout << head->data << " ";
}
void push(node **head, int val){
    node *newnode = create(val);
    if(*head == NULL){
        newnode ->nxt = *head;
        *head = newnode;
        return;
    }
    node *trv = *head;
    while(trv !=NULL && trv->nxt !=NULL)
        trv = trv->nxt;
    trv->nxt = newnode;
    return;
}
int main(){
    node *x = NULL;
    node *y = NULL;
    node *z = NULL;
    for(int i = 1; i < 11; i+= 2)
        push(&x, i);
    for(int i = 0; i < 11; i+= 2)
        push(&y, i);
    Display(x);
    Display(y);
    z = AddTwoNum(x, y);
    Display(z);
}
