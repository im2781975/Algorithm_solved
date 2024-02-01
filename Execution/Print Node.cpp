// Print all nodes between two given levels in a binary Node
#include<bits/stdc++.h>
using namespace std;
// Class containing left and right child of current node and key value
struct Node{
    int data;
    Node *left, *right;
};
Node* newNode(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
// Iterative function to print all nodes between two given levels in a binary Node
void printNodes(Node* root, int start, int end){
    if (root == NULL) return;
    // create an empty queue and enqueue root node
    queue<Node*> queue;
    queue.push(root);
    // pointer to store current node
    Node *curr = NULL;
    // maintains level of current node
    int level = 0;
    // run till queue is not empty
    while (!queue.empty()) {
        // increment level by 1
        level++;
        // calculate number of nodes in current level
        int size = queue.size();
        // process every node of current level and enqueue their non-empty left and right child to queue
        while (size != 0){
            curr = queue.front();
            queue.pop();
            // print the node if its level is between given levels
            if (level >= start && level <= end) cout<<curr->data<<" ";
            if (curr->left != NULL) queue.push(curr->left);
  
            if (curr->right != NULL) queue.push(curr->right);
            size--;
        }
        if (level >= start && level <= end) cout<<"\n";
    }
}
int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    /* Constructed binary Node is
         1
        / \
       2   3
      / \ / \
      4 5 6 7 */
  
    int start = 2, end = 3;
    printNodes(root, start, end);
}
