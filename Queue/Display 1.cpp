#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *nxt;
    node(int val):data(val), nxt(NULL){}
};
struct Queue{
    node *front, *rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void enQueue(int val){
        node *newnode = new node(val);
        if(rear == NULL){
            front = rear = newnode;
            return;
        }
        rear ->nxt = newnode;
        rear = newnode;
    }
    void deQueue(){
        if(front == NULL)
            return;
        node *tmp = front;
        front = front->nxt;
        if(front == NULL)
            rear = NULL;
        delete tmp;
    }
};
int main(){
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
    cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1);
}
