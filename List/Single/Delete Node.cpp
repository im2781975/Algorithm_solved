#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
 
    //link the old list of the new node
    new_node->next = (*head_ref);
 
    // move the head to point to the new node 
    (*head_ref) = new_node;
}
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void deleteNode(Node* node)
{
    Node* prev;
    if (node == NULL)
        return;
    else {
        Node* temp = node->next;
        node->data = temp->data;
        node->next = temp->next;
        temp = NULL;
    }
}
int main()
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    cout << "Before deleting \n";
    printList(head);
    deleteNode(head);
    cout << "\nAfter deleting \n";
    printList(head);
    return 0;
}
