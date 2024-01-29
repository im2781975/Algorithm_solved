//check if two linked lists are identical or not 
#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
    int data; 
    struct Node* next; 
};
bool areIdentical(struct Node* a, struct Node* b) 
{ 
    while (a != NULL && b != NULL) { 
        if (a->data != b->data) 
            return false; 
  
        // If we reach here, then a and b are not NULL and their data is same, so 
        //move to next nodes in both lists 
        a = a->next; 
        b = b->next; 
    } 
    // If linked lists are identical, then 'a' and 'b' must be NULL at this point. 
    return (a == NULL && b == NULL); 
}
void push(struct Node** head_ref, int new_data) 
{ 
    // allocate node
    struct Node* new_node 
        = (struct Node*)malloc(sizeof(struct Node)); 
  
    // put in the data 
    new_node->data = new_data; 
    // link the old list of the new node 
    new_node->next = (*head_ref); 
  
    // move the head to point to the new node 
    (*head_ref) = new_node; 
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
