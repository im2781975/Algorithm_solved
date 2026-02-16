// find minimum depth of a given Binary Tree
#include <bits/stdc++.h>
using namespace std;
// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int d = 0)
        : data{ d }{}
};
// A queue item (Stores pointer to node and an integer)
struct qItem {
    Node* node;
    int depth;
};
// Iterative method to find minimum depth of Binary Tree
int minDepth(Node* root)
{
    if (root == NULL)
        return 0;
    // Create an empty queue for level order traversal
    queue<qItem> q;
    // Enqueue Root and initialize depth as 1
    qItem qi = { root, 1 };
    q.push(qi);
    // Do level order traversal
    while (q.empty() == false) {
        // Remove the front queue item
        qi = q.front();
        q.pop();
 
        // Get details of the remove item
        Node* node = qi.node;
        int depth = qi.depth;
 
        // If this  is the first leaf node seen so far Then return its depth as answer
        if (node->left == NULL && node->right == NULL)
            return depth;
        // If left subtree is not NULL, add it to queue
        if (node->left != NULL) {
            qi.node = node->left;
            qi.depth = depth + 1;
            q.push(qi);
        }
        // If right subtree is not NULL, add it to queue
        if (node->right != NULL) {
            qi.node = node->right;
            qi.depth = depth + 1;
            q.push(qi);
        }
    }
    return 0;
}
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
 
    cout << minDepth(root);
    return 0;
}
// find minimum depth of a given Binary Tree
#include<bits/stdc++.h>
using namespace std;
// A BT Node
struct Node
{
    int data;
    struct Node* left, *right;
};
int minDepth(Node *root)
{
    if (root == NULL)
        return 0;
    // Base case : Leaf Node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL)
    return 1;
   
    int l = INT_MAX, r = INT_MAX;
    // If left subtree is not NULL, recur for left subtree
   
    if (root->left)
    l = minDepth(root->left);
 
    // If right subtree is not NULL, recur for right subtree
    if (root->right)
    r =  minDepth(root->right);
 
  //height will be minimum of left and right height +1 
    return min(l , r) + 1;
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}
int main()
{
    Node *root     = newNode(1);
    root->left     = newNode(2);
    root->right     = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout <<"The minimum depth of binary tree is : "<< minDepth(root);
    return 0;
}
