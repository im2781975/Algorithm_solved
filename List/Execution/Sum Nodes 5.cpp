// find the sum of last 'n' nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
 
//insert a node at the beginning
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// utility function to find the sum of last 'n' nodes
int sumOfLastN_NodesUtil(struct Node* head, int n)
{
    // if n == 0
    if (n <= 0)
        return 0;
 
    stack<int> st;
    int sum = 0;
    // traverses the list from left to right
    while (head != NULL) {
        // push the node's data onto the stack 'st'
        st.push(head->data);
        // move to next node
        head = head->next;
    }
    // pop 'n' nodes from 'st' and
    // add them
    while (n--) {
        sum += st.top();
        st.pop();
    }
    // required sum
    return sum;
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
