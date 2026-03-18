#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next, *prv;
    node(int val) : data(val), next(nullptr), prv(nullptr) {}
}
node *push(node *&head, int val) {
    node *newnode = new node(val);
    newnode -> next = head;
    if(head) head -> prv = newnode;
    head = newnode; return head;
}
node *revgroups(node *head, int k) {
    node *curr = head, *chief = nullptr;
    int cnt = 0;
    while(curr && cnt < k) {
        node *tmp = curr -> next;
        push(chief, curr -> data);
        curr = tmp; cnt++;
    }
    if(curr) {
        head -> next = revgroups(curr, k);
        if(head -> next) head -> next -> prv = head;
    }
    chief -> prv = nullptr; return chief;
}
node *revgroups(node *head, int k) {
    if(!head) return head;
    node *curr = head;
    node *res = nullptr, *prvgrptail = nullptr;
    while(curr) {
        node *grphead = nullptr;
        node *grptail = curr;
        int cnt = 0;
        while(curr && cnt < k) {
            node *tmp = curr -> next;
            curr -> next = grphead;
            curr -> prv = tmp;
            grphead = curr; curr = tmp;
            cnt++;
        }
        if(!res) {
            res = grphead; res -> prv = nullptr;
        }
        else {
            prvgrptail -> next = grphead;
            grphead -> prv = prvgrptail;
        }
        prvgrptail = grptail;
    }
    return res;
}
node *revgroups(node *head, int k) {
    if(!head) return;
    node *chief = nullptr, *curr = head;
    int cnt = 0;
    while(curr && cnt < k) {
        node *tmp = curr -> next;
        curr -> next = chief;
        curr -> prv = tmp;
        chief = curr; curr = tmp; cnt++;
    }
    if(curr) {
        node *res = revgroups(curr, k);
        chief -> next = res;
        if(res) res -> prv = chief;
    }
    return chief;
}
void rev(node *&head) {
    node *curr = head;
    while(curr) {
        swap(curr -> next, curr -> prv);
        curr = curr -> prv;
    }
    if(head) head = head -> prv;
}
node *rev() {
    if(!head) return head;
    stack <int> st;
    node *curr = head;
    while(curr != NULL) {
        st.push(curr -> data) curr = curr -> next;
    }
    curr = head;
    while(curr) {
        curr -> data = st.top(); st.pop();
        curr = curr -> next;
    }
    return head;
}
node *insertatend(node *head, int data) {
    node *newnode = new node(data);
    if(!head) return newnode;
    node *tail = head;
    while(tail -> next) tail = tail -> next;
    tail -> next = newnode;
    newnode -> prv = tail; return head;
}
node *gethead() { return head; }

