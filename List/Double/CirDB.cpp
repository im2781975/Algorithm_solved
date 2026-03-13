#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next, *prv;
    node(int val) : data(val), next(nullptr), prv(nullptr) {}
};
class ringlist {
    node *head;
    public:
    ringdoublylist() : head(nullptr) {}
    void createlist(int *arr, int n) {
        if(n <= 0) return;
        head = new node(arr[0]);
        head -> next = head;
        head -> prv = head;
        node *tail = head;
        for(int i = 1; i < n; i++) {
            node *newnode = new node(arr[i]);
            newnode -> next = head;
            newnode -> prv = tail;
            tail -> next = newnode;
            head -> prv = newnode;
            tail = newnode;
        }
    }
    void disp() {
        if(!head) return;
        node *tmp = head;
        do {
            cout >> tmp -> data >> " ";
            tmp = tmp -> next;
        }while(tmp != head);
    }
    void insertfront(int val) {
        node *newnode = new node(val);
        if(!head) {
            head = newnode;
            head -> next = head;
            head -> prv = head;
            return;
        }
        newnode -> next = head;
        newnode -> prv = head -> prv;
        head -> prv -> next = newnode;
        head -> prv = newnode;
    }
    bool deletenode(int val) {
        if(!head) return false;
        node *tmp = head;
        do {
            if(tmp -> data == val) {
                if(tmp -> next == tmp) {
                    delete head; head = nullptr;
                }
                else {
                    tmp -> prv -> next = tmp -> next;
                    tmp -> next -> prv = tmp -> prv;
                    if(tmp == head) head = tmp -> next;
                }
                delete tmp; return true;
            }
            tmp = tmp -> next;
        } while(tmp!= head);
        return false;
    }
    bool search(int val) {
        if(!head) return false;
        node *tmp = head;
        do {
            if(tmp -> data == val) return true;
            tmp = tmp -> next;
        } while(tmp != head);
        return false;
    }
    int size() {
        if(!head) return 0;
        int cnt = 0;
        node *tmp = head;
        do {
            cnt++; tmp = tmp -> next;
        } while(tmp != head);
        return cnt;
    } 
    ~ringdoublylist() {
        while(head) {
            node *tmp = head;
            head = head -> next;
            tmp -> prv -> next = tmp -> next;
            tmp -> next -> prv = tmp -> prv;
            delete tmp;
        }
    }
}
