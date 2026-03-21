#include<bits/stdc++.h>
//find length or count of nodes in a linked list
class node {
    public:
    int data; node *next;
}
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val;
    newnode -> next = *head;
    *head = newnode;
}
int getcnt(node *head, int cnt = 0) {
    if(!head) return cnt;
    getcnt(head -> next, cnt + 1);
}
int getcnt(node *head) {
    if(!head) return 0;
    else return 1 + getcnt(head -> next);
}
int getcnt(node *head) {
    int cnt = 0;
    node *curr = head;
    while(curr != NULL) {
        cnt++; curr = curr -> next;
    }
    return cnt;
}
int cntOccurance(node *head, int val) {
    node *curr = head; int cnt = 0;
    while(curr != NULL) {
        if(curr -> data == val) cnt++;
        curr = curr -> next;
    }
    return cnt;
}
struct node {
    int data; node *next;
}
int cntnodes(node *head) {
    node *slow = head; node *fast = head;
    while(slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            int cnt = 1;
            fast = slow -> next;
            while(fast != slow) {
                cnt++; fast = fast -> next;
            }
            return cnt;
        }
    }
    return 0;
}
int cntOccurance(node *head, int key) {
    if(!head) return 0;
    return (head -> data == key) + cntOccurance(head -> next, key);
}
int cntrotation(node *head) {
    int rotation = 0;
    while(head -> next && head -> data > head -> next -> data) {
        rotation++; head = head -> next;
    }
    return rotation;
}
// count nodes in loop
node *newnode(int key) {
    return new node{key, nullptr};
}
int cntnodesInloop(node *head) {
    unordered_set <node*> st;
    node *curr = head;
    while(curr) {
        if(st.count(curr)) {
            int cnt = 0;
            node *tmp = curr;
            do {
                cnt++; curr = curr -> next;
            } while(curr != tmp);
            return cnt;
        }
        st.insert(cnt);
        curr = curr -> next;
    }
}
// Count nodes in circular list
int cntnodes(node *head) {
    if(!head) return 0;
    int cnt = 0;
    node *tmp = head;
    do {
        cnt++; tmp = tmp -> next;
    } while(tmp != head)
    return cnt;
}

