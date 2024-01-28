#include <iostream>
 
struct Node {
    int data;
    Node* prev;
    Node* next;
};
 
void reverse(Node** head_ref) {
    Node* current = *head_ref;
    Node* temp = NULL;
 
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}
 
void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
}
 
int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
 
    // allocate nodes
    head = new Node();
    second = new Node();
    third = new Node();
 
    // link nodes
    head->data = 1;
    head->prev = NULL;
    head->next = second;
 
    second->data = 2;
    second->prev = head;
    second->next = third;
 
    third->data = 3;
    third->prev = second;
    third->next = NULL;
 
    std::cout << "Original List: ";
    printList(head);
 
    reverse(&head);
 
    std::cout << "\nReversed List: ";
    printList(head);
 
    return 0;
}
