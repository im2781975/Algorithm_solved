//find a pair with given sum x.  
#include<bits/stdc++.h>  
using namespace std;  
struct Node  
{  
    int data;  
    struct Node *next, *prev;  
};  
// Function to find pair whose sum equal to given value x.  
void pairSum(struct Node *head, int x)  
{  
    // Set two pointers, first to the beginning of DLL &  second to the end of DLL 
    struct Node *first = head;  
    struct Node *second = head;  
    while (second->next != NULL)  
        second = second->next;  
    // To track if we find a pair or not  
    bool found = false;  
  
    // The loop terminates when two pointers  cross each other (second->next == first), or they become same (first == second)  
    while (first != second && second->next != first)  
    {  
        // pair found  
        if ((first->data + second->data) == x)  
        {  
            found = true;  
            cout << "(" << first->data<< ", "
                << second->data << ")" << endl;  
            // move first in forward direction  
            first = first->next;  
            // move second in backward direction
            second = second->prev;
        }  
        else
        {  
            if ((first->data + second->data) < x)  
                first = first->next;  
            else
                second = second->prev;  
        }  
    }  
    // if pair is not present  
    if (found == false)  
        cout << "No pair found";  
}
// insert a new node at the beginning of doubly linked list
void insert(struct Node **head, int data)  
{  
    struct Node *temp = new Node;  
    temp->data = data;  
    temp->next = temp->prev = NULL;
    if (!(*head))  
        (*head) = temp;  
    else
    {  
        temp->next = *head;  
        (*head)->prev = temp;  
        (*head) = temp;  
    }  
}
int main()  
{  
    struct Node *head = NULL;  
    insert(&head, 9);  
    insert(&head, 8);  
    insert(&head, 6);  
    insert(&head, 5);  
    insert(&head, 4);  
    insert(&head, 2);  
    insert(&head, 1);  
    int x = 7;  
    pairSum(head, x);  
  
    return 0;  
}  
// find size
// find size of doubly linked list.
#include <bits/stdc++.h> 
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *next; 
    struct Node *prev; 
}; 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
    if ((*head_ref) !=  NULL) 
      (*head_ref)->prev = new_node ; 
    (*head_ref)    = new_node; 
} 
int findSize(struct Node *node) 
{ 
   int res = 0; 
   while (node != NULL) 
   { 
       res++; 
       node = node->next; 
   } 
   return res; 
}
int main() 
{ 
    struct Node* head = NULL; 
    push(&head, 4); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 1); 
    cout << findSize(head); 
    return 0; 
} 
// flattering
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;
 
    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
// comparator function for priority queue
struct mycomp {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
void flatten(Node* root)
{
    priority_queue<Node*, vector<Node*>, mycomp> p;
    // pushing main link nodes into priority_queue.
    while (root != NULL) {
        p.push(root);
        root = root->next;
    }
    // Extracting the minimum node while priority queue is not empty
    while (!p.empty()) {
        // extracting min
        auto k = p.top();
        p.pop();
        // printing  least element
        cout << k->data << " ";
        if (k->bottom)
            p.push(k->bottom);
    }
}
int main(void)
{
    // This code builds the flattened linked list of first picture in this article ;
    Node* head = new Node(5);
    auto temp = head;
    auto bt = head;
    bt->bottom = new Node(7);
    bt->bottom->bottom = new Node(8);
    bt->bottom->bottom->bottom = new Node(30);
    temp->next = new Node(10);
 
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(20);
    temp->next = new Node(19);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(22);
    bt->bottom->bottom = new Node(50);
    temp->next = new Node(28);
    temp = temp->next;
    bt = temp;
    bt->bottom = new Node(35);
    bt->bottom->bottom = new Node(40);
    bt->bottom->bottom->bottom = new Node(45);
 
    // Function call
    flatten(head);
    cout << endl;
    return 0;
}
// flattening a Linked List
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *right, *down;
};
Node* head = NULL;
// An utility function to merge two sorted linked lists
Node* merge(Node* a, Node* b)
{
    // If first linked list is empty then second is the answer
    if (a == NULL)
        return b;
    // If second linked list is empty then first is the result
    if (b == NULL)
        return a;
    // Compare the data members of the two linked lists and put the larger one in the result
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->down = merge(a->down, b);
    }
    else {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}
Node* flatten(Node* root)
{
    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;
    // Recur for list on right
    root->right = flatten(root->right);
    // Now merge
    root = merge(root, root->right);
    // Return the root it will be in turn merged with its left
    return root;
}
// Utility function to insert a node at beginning of the linked list
Node* push(Node* head_ref, int data)
{
    // Allocate the Node & Put in the data
    Node* new_node = new Node();
 
    new_node->data = data;
    new_node->right = NULL;
    // Make next of new Node as head
    new_node->down = head_ref;
    // Move the head to point to new Node
    head_ref = new_node;
    return head_ref;
}
void printList()
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}
int main()
{
 
    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |     |     |
        V    V     V     V
        7    20    22    35
        |          |     |
        V          V     V
        8          50    40
        |                |
        V                V
        30               45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);
 
    head->right = push(head->right, 20);
    head->right = push(head->right, 10);
 
    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);
 
    head->right->right->right
        = push(head->right->right->right, 45);
    head->right->right->right
        = push(head->right->right->right, 40);
    head->right->right->right
        = push(head->right->right->right, 35);
    head->right->right->right
        = push(head->right->right->right, 20);
 
    head = flatten(head);
    printList();
    return 0;
}
