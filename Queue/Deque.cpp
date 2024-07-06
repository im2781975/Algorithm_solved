#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *prv, *nxt;
    static node *create(int val){
        node *newnode = new node;
        newnode->prv = NULL;
        newnode->nxt = NULL;
        newnode->data = val;
        return newnode;
    }
};
class Deque{
    node *front, *rear;
    int size;
    public:
    Deque(){
        front = rear = NULL;
        size = 0;
    }
    void InsertFront(int data);
    void InsertRear(int data);
    void DeleteFront();
    void DeleteRear();
    int Front();
    int Back();
    int GetSize();
    bool IsEmpty();
    void Erase();
};
bool Deque::IsEmpty(){
    return (front == NULL);
}
int Deque::GetSize(){
    return size;
}
void Deque::InsertFront(int data){
    node *newnode = node::create(data);
    if(newnode == NULL)
        cout << "Overflow";
    else{
        if(front == NULL)
            front = rear = newnode;
        else{
            newnode->nxt = front;
            front->prv = newnode;
            front = newnode;
        }
        size++;
    }
}
void Deque::InsertRear(int data){
    node *newnode = node::create(data);
    if(newnode == NULL){
        cout << "Overflow";
    }
    else{
        if(rear == NULL)
            front = rear = newnode;
        else{
            newnode->prv = rear;
            rear->nxt = newnode;
            rear = newnode;
        }
        size++;
    }
}
void Deque::DeleteFront(){
    if(IsEmpty())
        cout << "\nEmpty";
    else{
        node *tmp = front;
        front = front->nxt;
        if(front == NULL)
            rear = NULL;
        else
            front->prv = NULL;
        free(tmp);
        size--;
    }
}
void Deque::DeleteRear(){
    if(IsEmpty())
        cout << "\nEmpty";
    else{
        node *tmp = rear;
        rear = rear->prv;
        if(rear == NULL)
            front = NULL;
        else
            rear->nxt = NULL;
        free(tmp);
        size--;
    }
}
int Deque::Front(){
    if(IsEmpty())
        return -1;
    return front->data;
}
int Deque::Back(){
    if(IsEmpty())
        return -1;
    return rear->data;
}
// Function to delete all the elements from Deque 
void Deque::Erase(){
    rear = NULL;
    while(front!=NULL){
        node *tmp = front;
        front = front->nxt;
        free(tmp);
    }
    size = 0;
}
int main(){
    Deque q;
    for(int i = 0; i < 5; i++){
        q.InsertFront(i);
    }
    while(q.Front() != -1){
        cout << q.Front();
        q.DeleteFront();
    }
}
