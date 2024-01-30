//arrange linked list in zigzag fashion
#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void push(node** head_ref, int new_data)
{
    node* new_Node = (node*)malloc(sizeof(node));
    new_Node->data = new_data;
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
// Rearrange the linked list in zig zag way
node* zigzag(node* head, bool flag)
{
    if (!head || !head->next)
        return head;
    if (flag == 1) {
        if (head->data > head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
    else {
        if (head->data < head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
}
void printList(node* head)
{
    while (head) {
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << "NULL";
}
int main()
{
 
    node* head = NULL;
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 15);
    push(&head, 11);
 
    printList(head);
    cout << endl;
 
    zigzag(head, 1);
    cout << "LL in zig zag fashion : " << endl;
    printList(head);
    return 0;
}
