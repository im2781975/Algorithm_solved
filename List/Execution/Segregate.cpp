// segregate even and odd nodes in a Linked List  
#include <bits/stdc++.h> 
using namespace std;
class Node  
{  
    public: 
    int data;  
    Node *next;  
};
void segregateEvenOdd(Node **head_ref)  
{  
    Node *end = *head_ref;  
    Node *prev = NULL;  
    Node *curr = *head_ref;  
    // Get pointer to the last node 
    while (end->next != NULL)  
        end = end->next;  
  
    Node *new_end = end;
    // Consider all odd nodes before the first even node and move then after end 
    while (curr->data % 2 != 0 && curr != end)  
    {  
        new_end->next = curr;  
        curr = curr->next;  
        new_end->next->next = NULL;  
        new_end = new_end->next;  
    }
    if (curr->data%2 == 0)  
    {  
        // Change the head pointer to point to first even node 
        *head_ref = curr;  
        //now current points to the first even node 
        while (curr != end)  
        {  
            if ( (curr->data) % 2 == 0 )  
            {  
                prev = curr;  
                curr = curr->next;
            }  
            else
            {  
                // break the link between prev and current 
                prev->next = curr->next;  
                // Make next of curr as NULL 
                curr->next = NULL;
                // Move curr to end 
                new_end->next = curr;  
                // make curr as new end of list
                new_end = curr; 
                // Update current pointer to next of the moved node
                curr = prev->next;
            }  
        }  
    }
    // We must have prev set before executing lines following this statement 
    else prev = curr;  
    //If there are more than 1 odd nodes and end of original list is odd then  
    // move this node to end to maintain same order of odd numbers in modified list 
    if (new_end != end && (end->data) % 2 != 0)  
    {  
        prev->next = end->next;  
        end->next = NULL;  
        new_end->next = end;  
    }  
    return;  
}
void push(Node** head_ref, int new_data)  
{
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);
    (*head_ref) = new_node;  
}
void printList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout << node->data <<" "; 
        node = node->next;  
    }  
}
int main()  
{
    Node* head = NULL;  
 
    push(&head, 11);  
    push(&head, 10);  
    push(&head, 8);  
    push(&head, 6);  
    push(&head, 4);  
    push(&head, 2);  
    push(&head, 0);  
  
    cout << "Original Linked list ";  
    printList(head);
    segregateEvenOdd(&head);  
    cout << "\nModified Linked list ";  
    printList(head);  
    return 0;  
}  
