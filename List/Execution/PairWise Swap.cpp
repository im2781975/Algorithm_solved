// pairwise swap elements in a given linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
// Function to pairwise swap elements of a linked list
void pairWiseSwap(Node* head)
{
    Node* temp = head;
    //Traverse further only if there are at-least two nodes left 
    while (temp != NULL && temp->next != NULL) {
        //Swap data of node with  its next node's data
        swap(temp->data,
             temp->next->data);
        // Move temp by 2 for the next pair
        temp = temp->next->next;
    }
}
//Recursive function to pairwise swap elements
void pairWiseSwap(node* head)
{
    //There must be at-least two nodes in the list
    if (head != NULL && head->next != NULL) {
        // Swap the node's data with data of next node 
        swap(head->data, head->next->data);
        pairWiseSwap(head->next->next);
    }
}
// Function to add a node at the beginning of Linked List 
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    // put in the data
    new_node->data = new_data;
    // link the old list of the new node 
    new_node->next = (*head_ref);
    /? move the head to point 
       to the new node
    (*head_ref) = new_node;
}
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    Node* start = NULL;
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    cout << "Linked list "
         << "before calling pairWiseSwap()\n";
    printList(start);
    pairWiseSwap(start);
 
    cout << "\nLinked list "
         << "after calling pairWiseSwap()\n";
    printList(start);
    return 0;
}
