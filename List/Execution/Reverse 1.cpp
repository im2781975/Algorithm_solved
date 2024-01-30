// reverse a linked list using two pointers. 
#include <bits/stdc++.h> 
using namespace std; 
typedef uintptr_t ut;
struct Node { 
    int data; 
    struct Node* next; 
}; 
//Function to reverse the linked list using 2 pointers 
void reverse(struct Node** head_ref) 
{ 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current->next != NULL) { 
        next = current->next; 
        current->next = next->next; 
        next->next = (*head_ref); 
        *head_ref = next; 
    } 
}
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}
void printList(struct Node* head) 
{ 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
}
int main() 
{
    struct Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 85); 
  
    printf("Given linked list\n"); 
    printList(head); 
    reverse(&head); 
    printf("\nReversed Linked list \n"); 
    printList(head); 
    return 0; 
} 
