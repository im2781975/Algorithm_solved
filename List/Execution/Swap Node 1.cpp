// swap two given nodes of a linked list
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    class Node* next;
    Node(int val, Node* next)
        : data(val), next(next){}
    // print list from this to last till null
    void printList()
    {
        Node* node = this;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};
void push(Node** head_ref, int new_data)
{
    // allocate node
    (*head_ref) = new Node(new_data, *head_ref);
}
void swap(Node*& a, Node*& b)
{
    Node* temp = a;
    a = b;
    b = temp;
}
void swapNodes(Node** head_ref, int x, int y)
{
    // Nothing to do if x and y are same
    if (x == y)
        return;
    Node **a = NULL, **b = NULL;
    // search for x and y in the linked list and store their pointer in a and b
    while (*head_ref) {
        if ((*head_ref)->data == x)
            a = head_ref;
        else if ((*head_ref)->data == y)
            b = head_ref;
        head_ref = &((*head_ref)->next);
    }
    // if we have found both a and b in the linked list swap current pointer and next pointer of these
    if (a && b) {
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}
int main()
{
    Node* start = NULL;
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    cout << "Linked list before calling swapNodes() ";
    start->printList();
 
    swapNodes(&start, 6, 1);
 
    cout << "Linked list after calling swapNodes() ";
    start->printList();
}
