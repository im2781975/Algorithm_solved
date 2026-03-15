#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *nxt;
    node(int val):data(val), nxt(nullptr){}
};
class single{
    node *head, *tail;
    public:
    single():head(nullptr), tail(nullptr){}
    void InsertFront(int val){
        node *newnode = new node(val);
        if(head == NULL)
            head = tail = newnode;
        else {
            newnode ->nxt = head;
            head = newnode;
        }
    }
    void InsertTail(int val){
        node *newnode = new node(val);
        if(head == NULL)
            head = tail = newnode;
        else {
            tail ->nxt = newnode;
            tail = newnode;
        }
    }
    void RemoveBack(){
        if(head == NULL){
            cout << "List Is Empty";
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else {
            node *a = head;
            while(a->nxt !=tail)
                a = a->nxt;
            delete tail;
            tail = a;
            tail->nxt = nullptr;
        }
    }
    int GetSize(){
        node *a = head;
        int cnt = 0;
        while(a !=NULL){
            cnt++;
            a = a->nxt;
        }
        return cnt;
    }
    void InsertMid(int val){
        int len = GetSize();
        if(len < 2)
            cout << "Should be exceed";
        node *newnode = new node(val);
        node *a = head;
        int cnt = 0;
        int mid = len/2;
        while(cnt < mid)
            a = a->nxt;
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    void RemoveMid(){
        int len = GetSize();
        if(len < 3){
            cout << "Should be exceed";
            return;
        }
        node *a = head;
        int mid = len/2;
        for(int i = 1; i < mid - 1; i++)
            a = a->nxt;
        node *tmp = a->nxt;
        a->nxt = tmp->nxt;
        delete tmp;
    }
    void Display(){
        node *a = head;
        while(a !=NULL){
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
};
void InsertHead(node *&head, int val){
        node *newnode = new node(val);
        if(head == nullptr){
            head = newnode;
            return;
        }
        newnode ->nxt = head;
        head = newnode;
    }
    void display(node *head){
        while(head !=NULL){
            cout << head->data << " ";
            head = head->nxt;
        }
    }
int main(){
    single sl;
    for(int i = 0; i < 5; i++){
        sl.InsertFront(i);
        sl.InsertTail(i+1);
    }
    sl.RemoveMid();
    sl.Display();
    //****//
    node* head = nullptr;
    InsertHead(head, 10);
    InsertHead(head, 20);
    InsertHead(head, 30);
    display(head);

    while (head != nullptr)
    {
        node* temp = head;
        head = head->nxt;
        delete temp;
    }
}
