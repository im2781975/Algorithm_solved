#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node();
    new_node->data = new_data; 
  
    //link the old list of the new node
    new_node->next = (*head_ref); 
    // move the head to point to the new node 
    (*head_ref) = new_node; 
} 
// A recursive C++ function to check if two linked lists are identical or not 
bool areIdentical(Node* a, Node* b) 
{ 
    // If both lists are empty 
    if (a == NULL && b == NULL) 
        return true; 
  
    // If both lists are not empty, then data of current nodes must match, and same should
    // be recursively true for rest of the nodes. 
    if (a != NULL && b != NULL) 
        return (a->data == b->data) 
               && areIdentical(a->next, b->next); 
    // If we reach here, then one of the lists is empty and other is not 
    return false; 
} 
int main() 
{ 
    struct Node* a = NULL; 
    struct Node* b = NULL; 
    push(&a, 1); 
    push(&a, 2); 
    push(&a, 3); 
    push(&b, 1); 
    push(&b, 2); 
    push(&b, 3); 
    // Function call 
    if (areIdentical(a, b)) 
        cout << "Identical"; 
    else
        cout << "Not identical"; 
  
    return 0; 
} 
