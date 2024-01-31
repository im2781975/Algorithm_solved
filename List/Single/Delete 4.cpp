// delete a node in
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int info;
    node* link = NULL;
    node() {}
    node(int a)
        : info(a) {}
};
// Deletes the node containing 'info' part as val and alter the head of the linked list (recursive method)
void deleteNode(node*& head, int val)
{
    // Check if list is empty or we reach at the end of the list.
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // If current node is the node to be deleted
    if (head->info == val) {
        node* t = head;
        // If it's start of the node head node points to second node
        head = head->link;
        // Else changes previous node's link to current node's link
        delete (t);
        return;
    }
    deleteNode(head->link, val);
}
// add a node in the linked list
void push(node*& head, int data)
{
    node* newNode = new node(data);
    newNode->link = head;
    head = newNode;
}
void print(node* head)
{
    // cout<<endl gets implicitly typecasted to bool value 'true'
    if (head == NULL and cout << endl)
        return;
    cout << head->info << ' ';
    print(head->link);
}
int main()
{
    node* head = NULL;
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);

    print(head);
    deleteNode(head, 20);
    print(head);
 
    deleteNode(head, 10);
    print(head);
 
    deleteNode(head, 14);
    print(head);
    return 0;
}
