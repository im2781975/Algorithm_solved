#include<bits/stdc++.h>
using namespace std;
//convert a Binary Tree to a Circular Doubly Linked List 
struct node {
    int data;
    node *left; node *right;
    node(int val): data(val), left(nullptr), right(nullptr) {}
};
node *concat(node *leftlist, node *rightlist) {
    if(!leftlist) return rightlist;
    if(!rightlist) return leftlist;
    node *lefttail = leftlist -> left;
    node *righttail = rightlist -> right;
    
    lefttail -> right = rightlist;
    rightlist -> left = lefttail;
    leftlist -> left = righttail;
    righttail -> right = leftlist;
    return leftlist;
}
node *treeToringlist(node *root) {
    if(!root) return nullptr;
    node *leftlist = treeToringlist(root -> left);
    node *rightlist = treeToringlist(root -> right);
    root -> left = root -> right = root;
    return concat(concat(leftlist, root), rightlist);
}
void display(node* head) {
    if (!head) return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->right;
    } while (curr != head);
    cout << " ";
}
