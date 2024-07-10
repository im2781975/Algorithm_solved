#include<iostream>
#include<stack>
using namespace std;
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
