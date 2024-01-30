//detect loop in a linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    int flag;
};
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->flag = 0;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
// Returns true if there is a loop in linked list else returns false.
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse it means there is a cycle
        // (Because you we encountering the node for the second time).
        if (h->flag == 1)
            return true;
        // If we are seeing the node for the first time, mark its flag as 1
        h->flag = 1;
        h = h->next;
    }
    return false;
}
int main()
{
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";
    return 0;
}
