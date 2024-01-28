// Modify the contents of the linked list 
#include <bits/stdc++.h> 
using namespace std;
struct Node 
{ 
    int data; 
    struct Node* next; 
};
void printList(struct Node*); 
// Function to insert a node at the beginning of the linked list 
void push(struct Node **head_ref, int new_data) 
{
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
  
    // link the old list at the end of the new node 
    new_node->next = *head_ref;  
  
    // move the head to point to the new node 
    *head_ref = new_node; 
}
void printList(struct Node *head) 
{ 
    if (!head) 
        return; 
      
    while (head->next != NULL) 
    { 
        cout << head->data << " -> "; 
        head = head->next; 
    } 
    cout << head->data << endl; 
} 
// Function to middle node of list
Node* find_mid(Node *head) 
{ 
    Node *temp = head, *slow = head, *fast = head ; 
      
    while(fast && fast->next) 
    { 
    // Advance 'fast' two nodes, and advance 'slow' one node 
    slow = slow->next ; 
    fast = fast->next->next ; 
    } 
    // If number of nodes are odd then update slow by slow->next; 
    if(fast) 
    slow = slow->next ; 
    return slow ; 
}
// function to modify the contents of the linked list. 
void modifyTheList(struct Node *head, struct Node *slow) 
{
    stack <int> s; 
    Node *temp = head ; 
  
    while(slow) 
    { 
        s.push( slow->data ) ; 
        slow = slow->next ; 
    } 
    // Traverse the list by using temp until stack is empty. 
    while( !s.empty() ) 
    { 
        temp->data = temp->data - s.top() ; 
        temp = temp->next ; 
        s.pop() ; 
    }
}
int main() 
{ 
    struct Node *head = NULL, *mid ;
    push(&head, 10); 
    push(&head, 7); 
    push(&head, 12); 
    push(&head, 8); 
    push(&head, 9); 
    push(&head, 2); 
      
    // Find the starting point of second half of list.  
    mid = find_mid(head) ; 
    // Call function to modify the contents of the linked list
    modifyTheList( head, mid);
    cout << "Modified List:" << endl; 
    printList(head); 
    return 0; 
}  
