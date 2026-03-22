// flatten list with next and child pointers  
#include <bits/stdc++.h> 
using namespace std; 
// Macro to find number of elements in array  
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))  
// A linked list node has data,   next pointer and child pointer
class Node  
{  
    public: 
    int data;  
    Node *next;  
    Node *child;  
};  
// create a linked list with n nodes. The data of nodes is taken from arr[]. All child pointers are set as NULL  
Node *createList(int *arr, int n) 
{  
    Node *head = NULL;  
    Node *p;  
  
    int i;  
    for (i = 0; i < n; ++i)  
    {  
        if (head == NULL)  
            head = p = new Node(); 
        else 
        {  
            p->next = new Node(); 
            p = p->next;  
        }  
        p->data = arr[i];  
        p->next = p->child = NULL;  
    }  
    return head;  
}  
// print all nodes of a linked list  
void printList(Node *head)  
{  
    while (head != NULL)  
    {  
        cout << head->data << " ";
        head = head->next;  
    }  
    cout<<endl;  
}
// creates the input list. The created list is same as shown in the above figure  
Node *createList(void)  
{  
    int arr1[] = {10, 5, 12, 7, 11};  
    int arr2[] = {4, 20, 13};  
    int arr3[] = {17, 6};  
    int arr4[] = {9, 8};  
    int arr5[] = {19, 15};  
    int arr6[] = {2};  
    int arr7[] = {16};  
    int arr8[] = {3};  
  
    Node *head1 = createList(arr1, SIZE(arr1));  
    Node *head2 = createList(arr2, SIZE(arr2));  
    Node *head3 = createList(arr3, SIZE(arr3));  
    Node *head4 = createList(arr4, SIZE(arr4));  
    Node *head5 = createList(arr5, SIZE(arr5));  
    Node *head6 = createList(arr6, SIZE(arr6));  
    Node *head7 = createList(arr7, SIZE(arr7));  
    Node *head8 = createList(arr8, SIZE(arr8));  
  
    // modify child pointers to  create the list shown above
    head1->child = head2;  
    head1->next->next->next->child = head3;  
    head3->child = head4;  
    head4->child = head5;  
    head2->next->child = head6;  
    head2->next->next->child = head7;  
    head7->child = head8;  
  
    // Return head pointer of first linked list. Note that all nodes are  reachable from head1 
    return head1;  
}  
  
//flattens a multilevel linked list 
void flattenList(Node *head)  
{
    if (head == NULL)  
    return;  
  
    Node *tmp;  
  
    // Find tail node of first level linked list 
    Node *tail = head;  
    while (tail->next != NULL)  
        tail = tail->next;  
    // One by one traverse through all nodes of first level  linked list till we reach the tail node  
    Node *cur = head;  
    while (cur != tail)  
    {  
        // If current node has a child  
        if (cur->child)  
        {  
            // then append the child at the end of current list  
            tail->next = cur->child;  
            // and update the tail to new last node  
            tmp = cur->child;  
            while (tmp->next)  
                tmp = tmp->next;  
            tail = tmp;  
        }
        // Change current node  
        cur = cur->next;  
    }  
}
int main(void)  
{  
    Node *head = NULL;  
    head = createList();  
    flattenList(head);  
    printList(head);  
    return 0;  
}  
#include <bits/stdc++.h> 
using namespace std;
struct Node { 
  
    int data; 
    Node *left, *right; 
};
// Function to create a new node with the given data 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
// An iterative function to do post order traversal of a given binary tree 
void postOrderIterative(Node* root) 
{ 
    if (root == NULL) 
        return;
    // Create two stacks 
    stack<Node *> s1, s2;
    // push root to first stack 
    s1.push(root); 
    Node* node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node);
        // Push left and right children of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    }
    // Print all elements of second stack 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
}
int main() 
{
    Node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6);
    root->right->right = newNode(7); 
    postOrderIterative(root); 
  
    return 0; 
} 
// print all ancestors of a given key 
#include <bits/stdc++.h> 
using namespace std;
// Structure for a tree node 
struct Node { 
    int data; 
    struct Node* left, *right; 
}; 
// A utility function to create a new tree node 
struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
// Iterative Function to print all ancestors of a given key 
void printAncestors(struct Node* root, int key) 
{ 
    if (root == NULL) 
        return;
    // Create a stack to hold ancestors 
    stack<struct Node*> st; 
    // Traverse the complete tree in postorder way till we find the key 
    while (1) { 
        // Traverse the left side. While traversing, push the nodes into  the stack so that their right subtrees can be traversed later 
        while (root && root->data != key) { 
            st.push(root);
            // push current node 
            root = root->left; 
            // move to next node 
        } 
        // If the node whose ancestors are to be printed is found, then break the while loop. 
        if (root && root->data == key) 
            break; 
        // Check if right sub-tree exists for the node at top, If not then pop that node because we don't need this node any more. 
        if (st.top()->right == NULL) { 
            root = st.top(); 
            st.pop(); 
  
            // If the popped node is right child of top, 
            // then remove the top as well. Left child of the top must have processed before. 
            while (!st.empty() && st.top()->right == root) { 
                root = st.top(); 
                st.pop(); 
            } 
        } 
        // if stack is not empty then simply set the root 
        // as right child of top and start traversing right sub-tree. 
        root = st.empty() ? NULL : st.top()->right; 
    }
    // If stack is not empty, print contents of stack. Here assumption is that the key is there in tree 
    while (!st.empty()) { 
        cout << st.top()->data << " "; 
        st.pop(); 
    } 
}
int main() 
{
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(7); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(8); 
    root->right->right = newNode(9); 
    root->left->left->left = newNode(4); 
    root->left->right->right = newNode(6); 
    root->right->right->left = newNode(10); 
  
    int key = 6; 
    printAncestors(root, key); 
  
    return 0; 
} 
