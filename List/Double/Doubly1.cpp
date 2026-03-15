#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt, *prv;
    node(int val):data(val), nxt(nullptr), prv(nullptr){}
};
class Doubly{
    public:
    node *head, *tail;
    int size;
    Doubly():head(nullptr), tail(nullptr), size(0){}
    void InsertFront(int val){
    node *newnode = new node(val);
        if(head == nullptr)
            head = tail = newnode;
        else {
            newnode->nxt = head;
            head->prv = newnode;
            head = newnode;
        }
        size++;
    }
    void Append(int val){
        node *newnode = new node(val);
        if(head == nullptr)
            head = tail = newnode;
        else{
            tail->nxt = newnode;
            newnode->prv = tail;
            tail = newnode;
        }
        size++;
    }
    void InsertMid(int val){
        node *newnode = new node(val);
        if(size == 0)
            head = tail = newnode;
        else if(size %2 == 0){
            node *a = head;
            for(int i = 0; i < size/2 -1; i++)
                a = a->nxt;
            newnode->prv = a;
            newnode->nxt = a->nxt;
            a->nxt->prv = newnode;
            a->nxt = newnode;
        }
        else {
        // Insert in the middle when the list has an odd number of elements
            node *a = head;
            for(int i = 0; i < size/2; i++)
                a = a->nxt;
            newnode->prv = a->prv;
            newnode->nxt = a->nxt;
            a->prv->nxt = newnode;
            a->nxt = newnode;
        }
        size++;
    }/*
    void InsertMid(int val){
        node *newnode = new node(val);
        if(head == NULL)
            head = tail = newnode;
        else if(head == tail){
            tail = newnode;
            head->nxt = newnode;
            newnode->prv = head;
        }
        else {
            node *a = head;
            int cnt = 0;
            while(a !=tail && cnt < 2){
                a = a->nxt;
                cnt++;
            }
            newnode->nxt = a;
            newnode->prv = a->prv;
            a->prv->nxt = newnode;
            a->prv = newnode;
        }
    }*/
    void RemoveBack(){
        if(tail == nullptr){
            cout << "underflow";
            return;
        }
        if(head == tail)
            head = tail = nullptr;
        else{
            node *tmp = tail;
            tail = tail ->prv;
            tail ->nxt = nullptr;
            delete tmp;
        }
        size--;
    }/*
    void RemoveBack(){
        if(tail !=nullptr){
            if(tail->prv !=nullptr){
                node *b = tail->prv;
                b->nxt = nullptr;
                delete tail;
                tail = b;
            }
            else {
                delete tail;
                head = tail = nullptr;
            }
        }
    }*/
    void RemoveFront(){
        if(head == nullptr){
            cout << "Underflow";
            return;
        }
        if(head == tail)
            head = tail = nullptr;
        else{
            node *tmp = head;
            head = head->nxt;
            head->prv = nullptr;
            delete tmp;
        }
        size--;
    }
    void RemoveMid(){
        if(size == 0)
            return;
        int mid = size/2;
        node *a = head;
        int cur = 0;
        while(a !=nullptr && cur < mid)
            a = a ->nxt;
        if(a->prv!=nullptr)
            a->nxt->prv = a->prv;
        if(a->nxt!=nullptr)
            a->prv->nxt = a->nxt;
        if(a == head)
            head = a->nxt;
        if(a == tail)
            tail = a->prv;
        delete a;
        size--;
    }
    void RemoveZero(){
        node *cur = head;
        while(cur !=nullptr){
            node *trv = cur->nxt;
            if(cur->data == 0){
                if(cur == head){
                    head = trv;
                    if(trv!=nullptr)
                        trv->prv = nullptr;
                    else {
                        cur->prv-> nxt = trv;
                        if(trv!=nullptr)
                        trv->prv = cur->prv;
                    }
                    delete cur;
                }
                cur = trv;
            }
        }
    }
    int SearchIdx(int idx){
        node *a = head;
        int curIdx = 0;
        while(a !=nullptr && curIdx < idx){
            a = a-> nxt;
            curIdx++;
        }
        if(a == nullptr){
            cout << "Idx doesn't found";
            return -1;
        }
        return a->data;
    }
    bool SearchDistinct(int val){
        node *a = head;
        while(a !=nullptr){
            if(a->data == val)
                return true;
            a = a->nxt;
        }
        return false;
    }
    void Reverse(){
        node *tmp = nullptr;
        node *a = head;
        while(a !=nullptr){
            tmp = a ->prv;
            a ->prv = a->nxt;
            a->nxt = tmp;
            a = a->prv;
        }
        if(tmp !=nullptr)
            head = tmp->prv;
    }
    void Insert(int idx, int val){
        if(idx == 0){
            InsertFront(val);
            return;
        }
        else{
            node *newnode = new node(val);
            node *a = head;
            int cur = 0;
            while(a!=nullptr && cur < idx){
                a = a->nxt;
                cur++;
            }
            if(a == nullptr){
                cout << "Idx not found";
                delete newnode;
                return;
            }
            newnode ->nxt = a->nxt;
            newnode->prv = a;
            if(a->nxt!=NULL){
                a->nxt->prv = newnode;
            }
            a->nxt = newnode;
            if(newnode->nxt == nullptr)
                tail = newnode;
        }
        size++;
    }
    void Erase(int val){
        size--;
        node *a = head;
        while(a!=nullptr){
            if(a->data == val){
                if(a->prv!=NULL)
                    a->prv->nxt = a->nxt;
                if(a->nxt!=NULL)
                    a->nxt->prv = a->prv;
                if(a == head)
                    head = a ->nxt;
                if(a == tail)
                    tail = a->prv;
                delete a;
                return;
            }
            a = a->nxt;
            
        }
        cout << "Value doesn't exits";
    }
    bool IsPalindrome(){
        node *a = head;
        node *b = tail;
        if(a!=nullptr && b!=nullptr && a !=b && b->nxt !=a){
            if(a->data != b->data)
                return false;
            a = a->nxt;
            b = b->prv;
        }
        return true;
    }
    void Display(){
        node *a = head;
        while(a !=nullptr){
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
    int GetSize(){
        return size;
    }
    int GetMax(){
        int max = head-> data;
        node *a = head->nxt;
        if(size == 0)
            return -1;
        while(a!=nullptr){
            if(a->data > max)
                max = a->data;
            a = a->nxt;
        }
        return max;
    }
    void DeleteMax(){
        if(size == 0)
            return;
        int max = GetMax();
        node *cur = head;
        while(cur != nullptr){
            if(cur->data == max){
                node *tmp = cur;
                if(cur->prv !=NULL)
                    cur->prv->nxt = cur->nxt;
                if(cur->nxt!=NULL)
                    cur->nxt->prv = cur->prv;
                if(cur == head)
                    head = cur->nxt;
                if(cur == tail)
                    tail = cur->prv;
                cur = cur->nxt;
                delete tmp;
                size--;
            }
            else
                cur = cur->nxt;
        }
    }
    node *getNodeAt(int idx){
        node *cur = head;
        int curIdx = 0;
        while(cur!=nullptr){
            cur = cur->nxt;
            curIdx++;
        }
        return cur;
    }
    void Swap(int i, int j){
        node *x = getNodeAt(i);
        node *y = getNodeAt(j);
        if(x!=nullptr && y!=nullptr){
            int trv = x->data;
            x->data = y->data;
            y->data = trv;
        }
    }
    ~Doubly(){
        node *cur = head;
        while(cur!=NULL) {
            node *tmp = cur;
            cur = cur->nxt;
            delete tmp;
        }
    }
};
int main(){
    Doubly Dl;
    for(int i = 0; i <= 10; i+= 2)
        Dl.InsertFront(i);
    Dl.Display();
    Dl.Reverse();
    Dl.Display();
    (Dl.IsPalindrome())? cout << "Yes": cout << "No";
    Dl.Erase(6);
    cout << Dl.GetSize();
    cout << Dl.GetMax();
    Dl.DeleteMax();
    Dl.Display();
    Dl.InsertMid(77);
    Dl.Display();
    return 0;
}
