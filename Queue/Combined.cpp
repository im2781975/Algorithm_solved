// implement stack and queue using Deque
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *nxt, *prv;
};
struct Deque{
    node *head, *tail;
    public:
    Deque(){
        head = tail = NULL;
    }
    bool IsEmpty(){
        if(head == NULL)
            return true;
        return false;
    }
    int size(){
        if(!IsEmpty()){
            int len = 0;
            node *tmp = head;
            while(tmp!=NULL){
                len++;
                tmp = tmp->nxt;
            }
            return len;
        }
        return 0;
    }
    void InsertFirst(int val){
        node *newnode = new node;
        newnode->data = val;
        if(head == NULL)
            head = tail = newnode;
        else{
            head ->prv = newnode;
            newnode->nxt = head;
            newnode->prv = NULL;
            head = newnode;
        }
    }
    void InsertLast(int val){
        node *newnode = new node;
        newnode->data = val;
        if(head == NULL)
            head = tail = newnode;
        else{
            newnode->prv = tail;
            tail->nxt = newnode;
            newnode->nxt = NULL;
            tail = newnode;
        }
    }
    void RemoveFirst(){
        if(!IsEmpty()){
            node *tmp = head;
            head = head->nxt;
            if(head != NULL)
                head->prv = NULL;
            delete tmp;
            if(head == NULL)
                tail = NULL;
            return;
        }
        cout << "\nList Is Empty";
    }
    void RemoveLast(){
        if(!IsEmpty()){
            node *tmp = tail;
            tail = tail->prv;
            if(tail !=NULL)
                tail->nxt = NULL;
            delete tmp;
            if(tail == NULL)
                head = NULL;
            return;
        }
    }
    void Display(){
        if(!IsEmpty()){
            node *tmp = head;
            while(tmp!=NULL){
                cout << tmp->data << " ";
                tmp = tmp->nxt;
            }
            cout << "\n";
        }
        else
            cout << "List Is Empty";
    }
};
class Stack :public Deque{
    public:
    void push(int val){
        InsertLast(val);
    }
    void pop(){
        RemoveLast();
    }
};
class Queue :public Deque{
    public:
    void enqueue(int val){
        InsertLast(val);
    }
    void Dequeue(){
        RemoveFirst();
    }
};
int main(){
    Stack st;
    for(int i = 1; i < 6; i++)
        st.push(i);
    st.pop();
    st.Display();
    Queue Q;
    for(int i = 5; i < 11; i++)
        Q.enqueue(i);
    Q.Dequeue();
    Q.Display();
    cout << "\nStack size: " << st.size();
    cout << "\nQueue size: " << Q.size();
}

