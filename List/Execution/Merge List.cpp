// merge two sorted linked lists
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
    // put in the data  
    new_node->data  = new_data;
    // link the old list off the new node 
    new_node->next = (*head_ref);
    // move the head to point to the new node 
    (*head_ref)    = new_node;
}
// Function to merge two sorted linked lists LL1 and LL2 without using any extra space.
void mergeLists(struct Node *a, struct Node * &b)
{
    // run till either one of a or b runs out
    while (a && b)
    {
        // for each element of LL1, compare it with first element of LL2.
        if (a->data > b->data)
        {
            // swap the two elements involve  if LL1 has a greater element
            swap(a->data, b->data);
            struct Node *temp = b;
            // To keep LL2 sorted, place first element of LL2 at its correct place
            if (b->next && b->data > b->next->data)
            {
                b = b->next;
                struct Node *ptr= b, *prev = NULL;
                // find mismatch by traversing the second linked list once
                while (ptr && ptr->data < temp->data)
                {
                    prev = ptr;
                    ptr = ptr -> next;
                }
                // correct the pointers
                prev->next = temp;
                temp->next = ptr;
            }
        }
        // move LL1 pointer to next element
        a = a->next;
    }
}
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "->" ;
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    struct Node *a = NULL;
    push(&a, 10);
    push(&a, 8);
    push(&a, 7);
    push(&a, 4);
    push(&a, 2);
 
    struct Node *b = NULL;
    push(&b, 12);
    push(&b, 3);
    push(&b, 1);
 
    mergeLists(a, b);
 
    cout << "First List: ";
    printList(a);
 
    cout << "Second List: ";
    printList(b);
 
    return 0;
}
