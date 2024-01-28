// modify the contents of the linked list 
#include <bits/stdc++.h> 
using namespace std;
struct Node 
{ 
    int data; 
    struct Node* next; 
};
void printList(struct Node*);
void push(struct Node **head_ref, int new_data) 
{ 
    struct Node* new_node = 
    (struct Node*) malloc(sizeof(struct Node)); 
    
    //put in the data
    new_node->data = new_data; 
    //link the old list at the end of the new node 
    new_node->next = *head_ref; 
    //move the head to point to the new node 
    *head_ref = new_node; 
}
void frontAndBackSplit(struct Node *head,  
    struct Node **front_ref, struct Node **back_ref) 
{ 
    Node *slow, *fast; 
    slow = head; 
    fast = head->next; 
      
    //Advance 'fast' two nodes, & advance 'slow' one node */
    while (fast != NULL) 
    { 
        fast = fast->next; 
        if (fast != NULL) 
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    // 'slow' is before the midpoint in the list, so split it in two at that point. 
    *front_ref = head; 
    *back_ref = slow->next; 
    slow->next = NULL; 
}
void reverseList(struct Node **head_ref) 
{ 
    struct Node *current, *prev, *next; 
    current = *head_ref; 
    prev = NULL; 
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }     
    *head_ref = prev; 
}
// perform the required subtraction operation on the 1st half of the linked list 
void modifyTheContentsOf1stHalf(struct Node *front, struct Node *back) 
{ 
    // traversing both the lists simultaneously 
    while (back != NULL) 
    { 
        // subtraction operation and node data  modification 
        front->data = front->data - back->data; 
          
        front = front->next; 
        back = back->next; 
    } 
}
// function to concatenate the 2nd(back) list at the end of 
// the 1st(front) list and returns the head of the new list 
struct Node* concatFrontAndBackList(struct Node *front,struct Node *back) 
{ 
    struct Node *head = front; 
    while (front->next != NULL) 
        front = front->next;     
         front->next = back; 
    return head; 
} 
// function to modify the contents of the linked list 
struct Node* modifyTheList(struct Node *head) 
{ 
    // if list is empty or contains only single node 
    if (!head || head->next == NULL) 
        return head; 
    struct Node *front, *back; 
      
    // split the list into two halves front and back lists 
    frontAndBackSplit(head, &front, &back);     
    // reverse the 2nd(back) list 
    reverseList(&back); 
    // modify the contents of 1st half     
    modifyTheContentsOf1stHalf(front, back); 
    // again reverse the 2nd(back) list 
    reverseList(&back); 
    // concatenating the 2nd list back to the end of the 1st list 
    head = concatFrontAndBackList(front, back); 
    // pointer to the modified list 
    return head; 
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
int main() 
{ 
    struct Node *head = NULL;
    // creating the linked list 
    push(&head, 10); 
    push(&head, 7); 
    push(&head, 12); 
    push(&head, 8); 
    push(&head, 9); 
    push(&head, 2); 
      
    // modify the linked list 
    head = modifyTheList(head);
    cout << "Modified List:" << endl; 
    printList(head); 
    return 0; 
}  
