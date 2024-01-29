// find the sum of last 'n' nodes of the Linked List
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
// function to insert a node at the beginning
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void sumOfLastN_Nodes(struct Node* head, int* n,int* sum)
{
    // if head = NULL
    if (!head)
        return;
    // recursively traverse the remaining nodes
    sumOfLastN_Nodes(head->next, n, sum);
    // if node count 'n' is greater than 0
    if (*n > 0) {
        // accumulate sum
        *sum = *sum + head->data;
        // reduce node count 'n' by 1
        --*n;
    }
}
// utility function to find the sum of last 'n' nodes
int sumOfLastN_NodesUtil(struct Node* head, int n)
{
    // if n == 0
    if (n <= 0)
        return 0;
    int sum = 0;
    // find the sum of last 'n' nodes
    sumOfLastN_Nodes(head, &n, &sum);
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
