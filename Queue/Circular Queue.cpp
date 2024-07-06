// insertion and deletion in Circular Queue
#include<iostream>
#include<climits>
using namespace std;
struct node{
    int data;
    node *nxt;
};
struct Queue{
    node *front, *rear;
};
void enqueue(Queue *q, int val){
    node *tmp = new node;
    tmp->data = val;
    if(q->front == NULL)
        q->front = tmp;
    else
        q->rear->nxt = tmp;
    q->rear = tmp;
    q->rear->nxt = q->front;
}
int dequeue(Queue *q){
    if(q->front == NULL){
        cout << "Queue is Empty";
        return INT_MIN;
    }
    int value;
    if(q->front == q->rear){
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else{
        node *tmp = q->front;
        value = tmp->data;
        q->front = q->front->nxt;
        q->rear->nxt = q->front;
        free(tmp);
    }
    return value;
}
void Display(Queue *q){
    node *tmp = q->front;
    cout << "\n";
    while(tmp->nxt!= q->front){
        cout << tmp->data << " ";
        tmp  = tmp->nxt;
    }
    cout << tmp->data << " ";
}
int main(){
    Queue *q = new Queue;
    q->front = NULL;
    q->rear = NULL;
    for(int i = 1; i < 11; i++){
        enqueue(q, i);
    }
    Display(q);
}
