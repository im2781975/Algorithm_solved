#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt;
    //node(int val):data(val), nxt(nullptr){}
};
class Singly{
    int size;
    node *head;
    public:
    Singly():size(0), head(nullptr){}
    node *create(int val){
        node *newnode = new node;
        newnode->data = val;
        newnode->nxt = NULL;
        return newnode;
    }
    void InsertFront(int val){
        size++;
        node *newnode = create(val);
       // node *newnode = new node(val);
        node *a = head;
        if(head == nullptr)
            head = newnode;
        newnode->nxt = head;
        head = newnode;
    }
    void InsertAnyIdx(int val, int idx){
        if(idx < 0 || idx > size)
            return;
        if(idx == 0){
            InsertFront(val);
            return;
        }
        size++;
        node *a = head;
        int curIdx = 0;
        while(curIdx != idx -1){
            a = a->nxt;
            curIdx++;
        }
        //node *newnode = new node(val);
        node *newnode = create(val);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    int GetVal(int idx){
        if(idx < 0 || idx > size)
            return -1;
        node *a = head;
        int curIdx = 0;
        while(a !=nullptr && cur_idx != idx){
            a = a->nxt;
            curIdx++;
        }
        if(a !=nullptr)
            return a->data;
        return -1;
    }
    int SearchDistinct(int val){
        node *a = head;
        int idx = 0;
        while(a !=NULL){
            if(a->data == val)
                return idx;
            a = a->nxt;
            idx++;
        }
        return -1;
    }
    void SearchAllValue(int val){
        node *a = head;
        int idx = 0;
        while(a !=NULL){
            if(a->data == val)
                cout << val << " " << idx << "\n";
            a = a->nxt;
            idx++;
        }
    }
    bool GetVal(int val){
        node *a = head;
        while(a!=NULL){
            if(a->data == val)
                return true;
            a = a->nxt;
        }
        return false;
    }
    void Append(int val){
        node *newnode = new node(val);
        if(head == nullptr){
            head =  newnode;
            return;
        }
        else {
            node *a = head;
            while(a->nxt !=nullptr)
                a = a->nxt;
            a->nxt = newnode;
        }
        size++;
    }
    void InsertAfter(int val, int x){
        node *a = head;
        while(a !=NULL){
            if(a->data == val)
                break;
            a = a->nxt;
        }
        if(a == NULL){
            cout << "Value doesn't exits";
            size++;
        }
        //node *newnode = new node(x);
        node *newnode = new node(x);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    void RemoveZero(){
        node *a = head;
        while(a!=nullptr && a->data == 0){
            node *tmp = head;
            head = head->nxt;
            delete tmp;
            size--;
        }
        if(head == nullptr)
            return;
        node *a = head;
        while(a->nxt !=nullptr){
            if(a->nxt->data == 0){
                node *tmp = a->nxt;
                a->nxt = a->nxt->nxt;
                delete tmp;
                size--;
            }
            else
                a = a->nxt;
        }
    }
    void RemoveFront(){
        if(head == nullptr)
            return;
        while(head !=nullptr){
            node *a = head;
            head = head->nxt;
            delete a;
            size--;
        }
    }
    int RemoveAnyIdx(int idx){
        if(idx < 0 || idx > size - 1)
            return;
        if(idx == 0){
            RemoveFront();
            return;
        }
        node *a = head;
        int curIdx = 0;
        while(curIdx < idx-1){
            a = a->nxt;
            curIdx++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }
    int GetSum(){
        node *a = head;
        int idx = 0, sum = 0;
        while(a !=nullptr){
            if(idx%2 == 1)
                sum += a->data;
            idx++;
            a = a->nxt;
        }
        return sum;
    }
    void RemoveLast(){
        if(head == nullptr)
            return;
        while(head !=nullptr){
            
            if(head->nxt == nullptr){
                delete head;
                head = nullptr;
            }
            else {
                node *cur = head;
                while(cur->nxt->nxt!=nullptr)
                    cur = cur->nxt;
                delete cur->nxt;
                cur->next = nullptr;
            }
        }
        size--;
    }/*
    int GetVal(int idx){
        node *cur = head;
        int curIdx = 0;
        while(cur!=nullptr){
            if(curIdx == idx )
                return cur->data;
            cur = cur->nxt;
            curIdx++;
        }
        return -1;
    }*/
    int GetVal(int idx){
        node *cur = head;
        int curIdx = 0;
        while(cur !=nullptr && curIdx < idx){
            cur = cur->nxt;
            curIdx++;
        }
        if(a !=nullptr)
            return a->data;
        return -1;
    }
    int GetLast(){
        if(head == NULL)
            return -1;
        node *a = head;
        while(a !=NULL)
            a = a->nxt;
        return a->data;
    }
    void Getsize(){
        int cnt = 0;
        node *a = head;
        while(a !=NULL){
            cnt++;
            a = a->nxt;
        }
        cout << cnt;
    }
    bool HasDuplicate(){
        node *a = head;
        while(a!=nullptr){
            node *b = a->nxt;
            while(b!=nullptr){
                if(a->data == b->data)
                    return true;
                b = b->nxt;
            }
            a = a->nxt;
        }
        return false;
    }
    void sortList(){
        if(head == nullptr || head->nxt == nullptr)
            return;
        node *a = head;
        bool swaped = true;
        node *b = nullptr;
        do {
            swaped = false;
            while(a->nxt !=b){
                if(a->data > a->nxt->data){
                    swap(a->data, a->nxt->data);
                    swaped = true;
                }
                a = a->nxt;
            }
            b = a;
        } while(swaped);
    }
    void ReverseRecur(node *a){
        if(a == NULL)
            return;
        ReverseRecur(a->nxt);
        cout << a->data << " ";
    }
    void Reverse(){
        ReverseRecur(head);
        cout << "\n";
    }
    void SwapFirst(){
        if(size >= 2){
            node *a = head;
            node *b = a->nxt;
            swap(a->data, b->data);
        }
    }
    double GetAvg(){
        node *a = head;
        int cnt = 0, sum = 0;
        while(a !=NULL){
            sum+= a->data;
            cnt++;
            a= a->nxt;
        }
        return sum/cnt;
    }
};

