// find size of doubly linked list.
#include <bits/stdc++.h> 
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *next; 
    struct Node *prev; 
}; 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
    if ((*head_ref) !=  NULL) 
      (*head_ref)->prev = new_node ; 
    (*head_ref)    = new_node; 
} 
int findSize(struct Node *node) 
{ 
   int res = 0; 
   while (node != NULL) 
   { 
       res++; 
       node = node->next; 
   } 
   return res; 
}
int main() 
{ 
    struct Node* head = NULL; 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
    cout << findSize(head); 
    return 0; 
} 
