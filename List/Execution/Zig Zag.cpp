// arrange linked list in zigzag fashion
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// function distributes the Node in zigzag fashion
void zigZagList(Node* head)
{
    // If flag is true, then next node should be greater in the desired output.
    bool flag = true;
    // Traverse linked list starting from head.
    Node* current = head;
    while (current->next != NULL) {
        if (flag) 
        //"<" relation expected
        {
            // If we have a situation like A > B > C where
            // A, B and C are consecutive Nodes in list we get A > B < C by swapping B and C
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else 
        //">" relation expected */
        {
            // If we have a situation like A < B < C where
            // A, B and C  are consecutive Nodes in list we get A < C > B by swapping B and C
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }
        current = current->next;
        flag = !flag; 
        //flip flag for reverse checking 
    }
}
void push(Node** head_ref, int new_data)
{
    struct Node* new_Node = new Node;
    new_Node->data = new_data;
    new_Node->next = (*head_ref);
    //move the head to point to the new Node 
    (*head_ref) = new_Node;
}
void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d->", Node->data);
        Node = Node->next;
    }
    printf("NULL");
}
int main(void)
{
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);
 
    printf("Given linked list \n");
    printList(head);
    zigZagList(head);
    printf("\nZig Zag Linked list \n");
    printList(head);
 
    return (0);
}
