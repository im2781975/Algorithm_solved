// find the sum of last 'n' nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
 
// insert a node at the beginning
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int sumOfLastN_NodesUtil(struct Node* head, int n)
{
    // if n == 0
    if (n <= 0)
        return 0;
 
    int sum = 0, temp = 0;
    struct Node* ref_ptr, *main_ptr;
    ref_ptr = main_ptr = head;
    // traverse 1st 'n' nodes through 'ref_ptr' and accumulate all node's data to 'sum'
    while (ref_ptr != NULL &&  n--) {                   
        sum += ref_ptr->data;
        // move to next node
        ref_ptr = ref_ptr->next;
    }
    // traverse to the end of the linked list
    while (ref_ptr != NULL) {
        // accumulate all node's data to 'temp' pointed by the 'main_ptr'
        temp += main_ptr->data;
        // accumulate all node's data to 'sum' pointed by the 'ref_ptr'
        sum += ref_ptr->data;
        // move both the pointers to their respective next nodes
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    // required sum
    return (sum - temp);
}
int main()
{
    struct Node* head = NULL;
    push(&head, 12);
    push(&head, 4);
    push(&head, 8);
    push(&head, 6);
    push(&head, 10);
 
    int n = 2;
    cout << "Sum of last " << n << " nodes = "
         << sumOfLastN_NodesUtil(head, n);
    return 0;
}
