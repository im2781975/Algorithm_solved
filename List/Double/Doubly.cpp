#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *nxt, *prv;
};
class Doubly{
    public:
    node *head;
    int size;
    Doubly(){
        head = NULL;
        size = 0;
    }
    node *create(int val){
        node *newnode = new node;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        newnode->data = val;
        return newnode;
    }
    void InsertFront(int val){
        size++;
        node *newnode = create(val);
        if(head ==NULL){
            head = newnode;
            return;
        }
        node *a = head;
        newnode-> nxt = a;
        a->prv = newnode;
        head = newnode;
    }
    void Append(int val) {
        size++;
        node *newnode = create(val);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node *a = head;
        while (a->nxt != NULL) {
            a = a->nxt;
        }
        a->nxt = newnode;
        newnode->prv = a;
    }
    void Display(){
        node *a = head;
        while(a !=NULL){
            cout << a->data << " ";
            a = a->nxt;
        }
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
    void SearchDistinctIdx(int val){
        node *a = head;
        int idx = 0;
        while(a !=NULL){
            if(a->data == val)
                cout << val << " " << idx << "\n";
            a = a->nxt;
            idx++;
        }
    }
    void Insert(int val, int idx){
        if(idx < 0 || idx > size)
            return;
        if(idx == 0){
            Append(val);
            return;
        }
        node *a = head;
        int curIdx = 0;
        while(curIdx !=idx - 1){
            if(a == NULL)
                break;
            a = a->nxt;
            curIdx++;
        }
        if(a == NULL)
            cout << "Cant Insert";
        node *newnode = create(val);
        newnode ->nxt = a->nxt;
        newnode->prv = a;
        a->nxt =newnode;
        size++;
    }
    void RemoveFront(){
        if(head == NULL)
            return;
        size--;
        node *a = head;
        head = a->nxt;
        delete a;
    }
    void RemoveAnyIdx(int idx){
        if(idx < 0 || idx - 1 > size)
            return;
        node *a = head;
        int curIdx= 0;
        while(curIdx !=idx){
            a = a->nxt;
            curIdx++;
        }
        node *b = a->prv;
        node *c = a->nxt;
        if(b !=NULL)
            b->nxt = c;
        if(c !=NULL)
            c->prv = b;
        delete a;
        if(idx == 0)
            head = c;
        size--;
    }
    void RemoveVal(int val){
        node *cur = head;
        while(cur !=NULL){
            if(cur->data == val){
                node *tmp = cur;
                if(cur->prv !=NULL)
                    cur->prv->nxt = cur->nxt;
                if(cur->nxt !=NULL)
                    cur->nxt->prv = cur->prv;
                if(cur == head)
                    head = cur-> nxt;
                cur = cur->nxt;
                size--;
                delete tmp;
            }
            else{
                cur = cur->nxt;
            }
        }
    }
    int GetSize(){
        int cnt = 0;
        node *a = head;
        while(a !=NULL){
            cnt++;
            a = a->nxt;
        }
        return cnt;
    }
    void InsertAfterValue(int val){
        node *a = head;
        while(a!=NULL){
            if(a->data == val)
                break;
            a = a->nxt;
        }
        if(a == NULL){
            cout << "Value didn't found";
            return;
        }
        size++;
        node *newnode = create(val);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        a->nxt = newnode;
    }
    void RecurReverse(node *a){
        if(a == NULL)
            return;
        RecurReverse(a -> nxt);
        cout << a->data << " ";
    }
    void Reverse(){
        if(head == NULL)
            return;
        node *a = head;
        int curIdx = 0;
        while(curIdx !=size - 1){
            a = a->nxt;
            curIdx++;
        }
        node *b = head;
        while(b !=NULL){
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }
    void SwapIdx(int i, int j){
        if(i >= size && j >= size)
            return;
        node *x = head;
        int curIdx = 0;
        while(curIdx!= i){
            x = x->nxt;
            curIdx++;
        }
        node *y = head;
        curIdx = 0;
        while(curIdx!= j){
            y = y->nxt;
            curIdx++;
        }
        int tmp = x->data;
        x->data = y->data;
        y->data = tmp;
    }
};
int main(){
    Doubly Dl;
    for(int i = 0; i < 10; i++)
        Dl.Append(i);
    Dl.Display();
}
