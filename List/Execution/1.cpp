#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
};
void push(Node** head, int data) {
    Node* node = new Node();
    node -> data = data;
    node -> next = *head;
    *head = node;
}
void reverse(node **head) {
    node *curr = *head, *prv = nullptr;
    while(curr) {
        node *tmp = curr -> next;
        curr -> next = prv;
        prv = curr; curr = next;
    }
    *head = prv;
}
// Reverses the linked list in groups of size k
node *reverseK(node *head, int k) {
    if(!head) return nullptr;
    node *curr = head, *prv = nullptr, *tmp = nullptr;
    int cnt = 0;
    while(curr && cnt < k) {
        tmp = curr -> next;
        curr -> next = prv;
        prv = curr; curr = tmp; cnt++;
    }
    if(curr) head -> next = reverseK(curr, k);
    return prv;
}
node *reverse(node *head) {
    if(!head ||!head -> next) return head;
    node *res = reverse(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return res;
}
void reverse(Node** head) {
    if (!*head) return;
    util(*head, nullptr, head);
}
void util(node *curr, node *prv, node **head) {
    node *tmp = curr -> next;
    curr -> next = prv;
    if(!tmp) {
        *head = curr; return;
    }
    util(tmp, curr, head);
}
